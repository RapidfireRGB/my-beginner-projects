#include <filesystem>
#include <iostream>
#include <windows.h>
//#include <ctime>
//#include <cmath>

FILETIME ftCreate;
FILETIME ftAccess;
FILETIME ftWrite;
SYSTEMTIME stUTC, stLocal;

time_t get_created_at(const std::filesystem::path &file_path) {
    HANDLE hFile = CreateFileW(file_path.c_str(),
                               GENERIC_READ,
                               FILE_SHARE_READ,
                               nullptr,
                               OPEN_EXISTING,
                               FILE_ATTRIBUTE_NORMAL,
                               nullptr);

    //Revisit this part of the function.
    if (exists(file_path)) {
        const time_t created_at = !GetFileTime(hFile, &ftCreate, &ftAccess, &ftWrite);

        FileTimeToSystemTime(&ftWrite, &stUTC);
        SystemTimeToTzSpecificLocalTime(nullptr, &stUTC, &stLocal);

        //TODO try to turn this block into return statement
        std::cout << "Created on: " << "\n" << "Year: " << stLocal.wYear << "\n"
        << "Month: "<< stLocal.wMonth << "\n" << "Day: " << stLocal.wDay << "\n"
        << "Hour: " << stLocal.wHour << "\n" << "Minute: " << stLocal.wMinute << "\n"
        << "Second: " << stLocal.wSecond;


        return created_at;
    } else {
        //Error handle here.
        return -1;
    }
}

time_t get_modified_at(std::filesystem::path file_path) {
    //Fetch timestamp for any changes saved to file. Should return time data.
    //HANDLE hFile = CreateFileW(file_path.c_str(),
        //);


}

size_t get_file_size(std::filesystem::path file_path) {
    //When File is saved, get new file size.
}

size_t get_size_change(std::filesystem::path file_path) {
    //Find difference in size. Should return how much size has changed since last edit.
}

int main() {

    std::string full_dir;
    std::cout << "Paste the full path of a file you wish to log: " << "\n";
    std::cin >> full_dir;

    get_created_at(full_dir);

    //Output creation timestamp, edit timestamp, file size, and file size change
    //Export to a .txt
    return 0;
}