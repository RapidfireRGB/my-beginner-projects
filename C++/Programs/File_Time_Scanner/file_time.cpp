#include <filesystem>
#include <iostream>
#include <windows.h>
#include <fstream>
//#include <ctime>
//#include <cmath>

FILETIME ftCreate, ftAccess, ftWrite;
SYSTEMTIME stUTC, stLocal, stLocalTime;

// Prints 'created' timestamp of a target file to the console.
void get_created_at(const std::filesystem::path &file_path) {
    HANDLE hFile = CreateFileW(file_path.c_str(),
                               GENERIC_READ,
                               FILE_SHARE_READ,
                               nullptr,
                               OPEN_EXISTING,
                               FILE_ATTRIBUTE_NORMAL,
                               nullptr);

    // Throw error if file is not found
    if (!GetFileTime(hFile, &ftCreate, &ftAccess, &ftWrite) || !exists(file_path)) {
        std::cerr << "File does not exist or was not found. Make sure you paste the "
                     "path and file name correctly without quotation marks.\n";
    }

    FileTimeToSystemTime(&ftCreate, &stUTC);
    SystemTimeToTzSpecificLocalTime(nullptr, &stUTC, &stLocal);
    CloseHandle(hFile);

    // Defining tm struct created_at so time names make sense below.
    tm created_at{};
    created_at.tm_year = stLocal.wYear - 1900;
    created_at.tm_mon = stLocal.wMonth - 1;
    created_at.tm_mday = stLocal.wDay;
    created_at.tm_hour = stLocal.wHour;
    created_at.tm_min = stLocal.wMinute;
    created_at.tm_sec = stLocal.wSecond;

    std::cout << "Created on:\n"
    << created_at.tm_mon + 1 <<"/"<< created_at.tm_mday <<"/"<< created_at.tm_year - 100 << "\n"
    << created_at.tm_hour <<":"<< created_at.tm_min <<":"<< created_at.tm_sec << "\n\n";
}

//Prints 'last edited' timestamp of a target file to the console.
void get_modified_at(const std::filesystem::path &file_path) {
    HANDLE hFile = CreateFileW(file_path.c_str(),
        GENERIC_READ,
        FILE_SHARE_READ,
        nullptr,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        nullptr);

    // Throw an error if file is not found.
    if (!GetFileTime(hFile, &ftCreate, &ftAccess, &ftWrite) || !exists(file_path)) {
        std::cerr << "File does not exist or was not found. Make sure you paste the "
                     "path and file name correctly without quotation marks.\n";
    }

    FileTimeToSystemTime(&ftWrite, &stUTC);
    SystemTimeToTzSpecificLocalTime(nullptr, &stUTC, &stLocal);
    CloseHandle(hFile);

    // Defining tm struct created_at so time names make sense below.
    tm last_edit{};
    last_edit.tm_year = stLocal.wYear - 1900;
    last_edit.tm_mon = stLocal.wMonth - 1;
    last_edit.tm_mday = stLocal.wDay;
    last_edit.tm_hour = stLocal.wHour;
    last_edit.tm_min = stLocal.wMinute;
    last_edit.tm_sec = stLocal.wSecond;

    std::cout << "Last Modified at:\n"
    << last_edit.tm_mon + 1 <<"/"<< last_edit.tm_mday <<"/"<< last_edit.tm_year - 100<< "\n"
    << last_edit.tm_hour <<":"<< last_edit.tm_min <<":"<< last_edit.tm_sec << "\n\n";
}

// Returns target file's size in Bytes.
long long get_file_size(const std::filesystem::path &file_path) {
    HANDLE hFile = CreateFileW(file_path.c_str(),
        GENERIC_READ,
        FILE_SHARE_READ | FILE_SHARE_WRITE,
        nullptr,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        nullptr);

    LARGE_INTEGER file_size;

    //Throw an error if file size can't be fetched
    if (hFile == INVALID_HANDLE_VALUE || !GetFileSizeEx(hFile, &file_size)) {
        std::cerr << "\nCould not fetch file size.\n";
    }
    CloseHandle(hFile);

    //Attempting to comma separate large Byte values. Work in progress.
    //for LARGE INT i = file_size.QuadPart && int n = 0; i % 10^(3+n); n+3
        //add comma separators to file_size.QuadPart until INT i cannot be divided by 1,000, 1,000,000, etc

    return file_size.QuadPart;
}

//Returns true if target file is in the same directory as the .exe, or false if not.
bool is_in_same_dir (const std::filesystem::path &file_path) {
    std::filesystem::path exe_path;
    if (exe_path == file_path.parent_path()) {
        return true;
    }
    return false;
}

//TODO revisit this concept.
//size_t get_size_change(const std::filesystem::path& file_path) {
    //Find difference in size. Should return how much size has changed since last edit.
//}

int call_count = 0;
int main() {
    const std::filesystem::path exe_path = std::filesystem::current_path();

    //Initial console prompt
    std::string full_dir;
    std::cout << "Paste the full path of a file you wish to log:\n";
    std::cin >> full_dir;

    //Throw an error if the target file is not in the same directory as the .exe.
    if (is_in_same_dir(full_dir) == false) {
        std::cerr << "\nERROR: Target file is in a different directory than the .exe. It may not read the file info correctly.\n\n";
    }

    //Prints file info to the console.
    get_created_at(full_dir);
    get_modified_at(full_dir);
    std::cout << "File Size: " << get_file_size(full_dir) << " Bytes\n\n";

    //Checks if user wants to save the console output to a file.
    char user_wants_log;
    std::cout << "Would you like to save this to a .txt file? (y/n)";
    std::cin >> user_wants_log;

    if (user_wants_log == 'y') {
        if (std::ofstream log("filetime_info.txt"); log.is_open()) {
            freopen("filetime_info.txt", "w", stdout);
            //This block gets saved.
            std::cout << full_dir << ":\n";
            get_created_at(full_dir);
            get_modified_at(full_dir);
            std::cout << "File Size: " << get_file_size(full_dir) << " Bytes\n";
            std::cout << "----------------------\n";
            freopen("CON", "w", stdout);

            if (log.is_open() && get_file_size("filetime_info.txt") > 0) {
                std::cout << "Successfully wrote to file.";
                log.close();
            } else {
                std::cerr << "\n\nERROR: File could not be saved.";
            }
        } else {
            std::cerr << "\n\nERROR:'logfile.txt' could not be opened.";
        }
    }

    //Early termination if user keeps calling main.
    if (call_count == 10) {
        return 0;
    }

    char final_check;
    std::cout << "\n\nWould you like to fetch the info of another file? (y/n)";
    std::cin >> final_check;
    if (final_check == 'y') {
        call_count += 1;
        main();
    }
    return 0;
}

