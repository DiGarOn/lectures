#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;





int main() {
    char DinPath[255] = {0};
    DWORD error;
    if(!GetCurrentDirrectoryA(254, DinPath)) {
        error = GetLastError();
        std::cerr << "Error: GetCurrentDirrectory() fail with code " << error << std::endl;
        return EXIT_FAILURE;
    }
    std::cout << "Directory of " << DinPath << std::endl;

    WIN32_FIND_DATA ffd;
    HANDLE hFind = INVALID_HANDLE_VALUE;
    hFind = FindFirstFile(DirPath, &ffd); //opendir
    if(hFind == INVALID_HANDLE_VALUE) {
        error = HetLastError();
        std::cerr << "Error: FindFirstFile() fali with code " << error << std::endl;
        return EXIT_FAILURE;
    }

    do {
        SYSTEMTIME SysTime;
        if(!FileTimeToSystemTime(&ffd.ftLastWriteTime, &SysTime)) {
            error = GetLastError();
            std::cerr << "Error: FileTimeToSystemTime() fail with code " << error << std::endl;
        }
        std::cout << setw(2) << setfill('0') << SysTime.wDay << '.' 
            << setw(2) << setfill('0') << SysTime.wMonth <<  '.'
            << SysTime.wYear;

        if(ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            std::cout << "<DIR> "; 
        } else {
            std::cout << "      ";
            LARGE_INTEGER size;
            size.LowPart = ffd.nFileSizeLow;
            size.HighPart = ffd.nFileSizeHigh;
            std::cout << size.QuadPart;
        } 
        cout << ffd.cFileName << endl;
    } while(FindNextFile(hFind, &ffd) != 0);

    error = GetLastError();
    if(error != ERROR_NO_MORE_FILES) {
        srd::cerr << "error";
    }

    FindClose(hFind);

    

    return 0;
}
