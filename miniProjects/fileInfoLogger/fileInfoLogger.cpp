#include <filesystem>
#include <iostream>
#include <windows.h>
//#include <ctime>
//#include <cmath>

FILETIME ftCreate;
FILETIME ftAccess;
FILETIME ftWrite;
SYSTEMTIME stUTC, stLocal, stLocalTime;

time_t get_created_at(const std::filesystem::path &file_path) {
    HANDLE hFile = CreateFileW(file_path.c_str(),
                               GENERIC_READ,
                               FILE_SHARE_READ,
                               nullptr,
                               OPEN_EXISTING,
                               FILE_ATTRIBUTE_NORMAL,
                               nullptr);

    //Revisit this part of the function.
    if (!GetFileTime(hFile, &ftCreate, &ftAccess, &ftWrite) || !exists(file_path)) {
        //Error handle here.
        std::cerr << "File does not exist or was not found. Make sure you paste the "
                     "path and file name correctly without quotation marks." << "\n";
        return -1;
    }

    FileTimeToSystemTime(&ftCreate, &stUTC);
    SystemTimeToTzSpecificLocalTime(nullptr, &stUTC, &stLocal);
    CloseHandle(hFile);

    //TODO move this to main.
    std::cout << "Created on: " << "\n" << "Year: " << stLocal.wYear << "\n"
    << "Month: "<< stLocal.wMonth << "\n" << "Day: " << stLocal.wDay << "\n"
    << "Hour: " << stLocal.wHour << "\n" << "Minutes: " << stLocal.wMinute << "\n"
    << "Seconds: " << stLocal.wSecond << "\n";

    // conversion to time_t
    tm created_at{};
    created_at.tm_year = stLocal.wYear - 1900;
    created_at.tm_mon = stLocal.wMonth - 1;
    created_at.tm_mday = stLocal.wDay;
    created_at.tm_hour = stLocal.wHour;
    created_at.tm_min = stLocal.wMinute;
    created_at.tm_sec = stLocal.wSecond;

    return mktime(&created_at);
}

time_t get_modified_at(const std::filesystem::path &file_path) {
    //Fetch timestamp for last change saved to file. Should return time data.
    HANDLE hFile = CreateFileW(file_path.c_str(),
        GENERIC_READ,
        FILE_SHARE_READ,
        nullptr,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        nullptr);

    if (!GetFileTime(hFile, &ftCreate, &ftAccess, &ftWrite) || !exists(file_path)) {
        //Handle error here.
        return -1;
    }

    FileTimeToSystemTime(&ftWrite, &stUTC);
    SystemTimeToTzSpecificLocalTime(nullptr, &stUTC, &stLocal);
    CloseHandle(hFile);

    // TODO move this to main.
    std::cout << "Last Modified at: " << "\n" << "Year: " << stLocal.wYear << "\n"
        << "Month: "<< stLocal.wMonth << "\n" << "Day: " << stLocal.wDay << "\n"
        << "Hour: " << stLocal.wHour << "\n" << "Minutes: " << stLocal.wMinute << "\n"
        << "Seconds: " << stLocal.wSecond << "\n";

    // conversion to time_t
    tm last_edit{};
    last_edit.tm_year = stLocal.wYear - 1900;
    last_edit.tm_mon = stLocal.wMonth - 1;
    last_edit.tm_mday = stLocal.wDay;
    last_edit.tm_hour = stLocal.wHour;
    last_edit.tm_min = stLocal.wMinute;
    last_edit.tm_sec = stLocal.wSecond;

    return mktime(&last_edit);
}

long long get_file_size(const std::filesystem::path &file_path) {
    //When File is saved, get new file size.
    HANDLE hFile = CreateFileW(file_path.c_str(),
        GENERIC_READ,
        FILE_SHARE_READ | FILE_SHARE_WRITE,
        nullptr,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        nullptr);

    LARGE_INTEGER file_size;
    CloseHandle(hFile);
    return file_size.QuadPart;

}

size_t get_size_change(std::filesystem::path file_path) {
    //Find difference in size. Should return how much size has changed since last edit.
}

int main() {

    std::string full_dir;
    std::cout << "Paste the full path of a file you wish to log: " << "\n";
    std::cin >> full_dir;

    get_created_at(full_dir);
    get_modified_at(full_dir);
    std::cout << "The size is: " << get_file_size(full_dir);


    //Output creation timestamp, edit timestamp, file size, and file size change
    //Export to a .txt
    return 0;
}