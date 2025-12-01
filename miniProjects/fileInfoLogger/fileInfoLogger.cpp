#include <filesystem>
#include <iostream>
#include <windows.h>
//#include <ctime>
//#include <cmath>

FILETIME ftCreate, ftAccess, ftWrite;
SYSTEMTIME stUTC, stLocal, stLocalTime;

void get_created_at(const std::filesystem::path &file_path) {
    HANDLE hFile = CreateFileW(file_path.c_str(),
                               GENERIC_READ,
                               FILE_SHARE_READ,
                               nullptr,
                               OPEN_EXISTING,
                               FILE_ATTRIBUTE_NORMAL,
                               nullptr);

    if (!GetFileTime(hFile, &ftCreate, &ftAccess, &ftWrite) || !exists(file_path)) {
        //Error handle here.
        std::cerr << "File does not exist or was not found. Make sure you paste the "
                     "path and file name correctly without quotation marks." << "\n";
    }

    FileTimeToSystemTime(&ftCreate, &stUTC);
    SystemTimeToTzSpecificLocalTime(nullptr, &stUTC, &stLocal);
    CloseHandle(hFile);

    // defining tm struct created_at so time names make sense below.
    tm created_at{};
    created_at.tm_year = stLocal.wYear - 1900;
    created_at.tm_mon = stLocal.wMonth - 1;
    created_at.tm_mday = stLocal.wDay;
    created_at.tm_hour = stLocal.wHour;
    created_at.tm_min = stLocal.wMinute;
    created_at.tm_sec = stLocal.wSecond;

    //TODO move this to main.
    std::cout << "Created on:\n"
    << created_at.tm_mon + 1 <<"/"<< created_at.tm_mday <<"/"<< created_at.tm_year - 100 << "\n"
    << created_at.tm_hour <<":"<< created_at.tm_min <<":"<< created_at.tm_sec << "\n\n";

    //return created_at;
}

void get_modified_at(const std::filesystem::path &file_path) {
    HANDLE hFile = CreateFileW(file_path.c_str(),
        GENERIC_READ,
        FILE_SHARE_READ,
        nullptr,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        nullptr);

    if (!GetFileTime(hFile, &ftCreate, &ftAccess, &ftWrite) || !exists(file_path)) {
        std::cerr << " ";
    }

    FileTimeToSystemTime(&ftWrite, &stUTC);
    SystemTimeToTzSpecificLocalTime(nullptr, &stUTC, &stLocal);
    CloseHandle(hFile);

    // defining tm struct created_at so time names make sense below.
    tm last_edit{};
    last_edit.tm_year = stLocal.wYear - 1900;
    last_edit.tm_mon = stLocal.wMonth - 1;
    last_edit.tm_mday = stLocal.wDay;
    last_edit.tm_hour = stLocal.wHour;
    last_edit.tm_min = stLocal.wMinute;
    last_edit.tm_sec = stLocal.wSecond;

    // TODO move this to main.
    std::cout << "Last Modified at:\n"
    << last_edit.tm_mon + 1 <<"/"<< last_edit.tm_mday <<"/"<< last_edit.tm_year - 100<< "\n"
    << last_edit.tm_hour <<":"<< last_edit.tm_min <<":"<< last_edit.tm_sec << "\n\n";

    //return last_edit

}

long long get_file_size(const std::filesystem::path &file_path) {
    HANDLE hFile = CreateFileW(file_path.c_str(),
        GENERIC_READ,
        FILE_SHARE_READ | FILE_SHARE_WRITE,
        nullptr,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        nullptr);

    LARGE_INTEGER file_size;
    if (hFile == INVALID_HANDLE_VALUE || !GetFileSizeEx(hFile, &file_size)) {
        return -1;
    }
    CloseHandle(hFile);

    return file_size.QuadPart;

}

//size_t get_size_change(const std::filesystem::path& file_path) {
    //Find difference in size. Should return how much size has changed since last edit.
//}

int main() {
    std::string full_dir;
    std::cout << "Paste the full path of a file you wish to log:\n";
    std::cin >> full_dir;

    get_created_at(full_dir);
    get_modified_at(full_dir);
    std::cout << "File Size: " << get_file_size(full_dir) << " Bytes\n";

    //Output creation timestamp, edit timestamp, file size, and file size change
    //Export to a .txt
    return 0;
}