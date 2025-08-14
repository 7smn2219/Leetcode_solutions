#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <windows.h>

bool endsWith(const std::string& str, const std::string& suffix) {
    return str.size() >= suffix.size() &&
           str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: time <program.cpp | program.exe>\n";
        return 1;
    }

    std::string inputFile = argv[1];
    std::string exeFile;

    // If it's a .cpp file, compile it
    if (endsWith(inputFile, ".cpp")) {
        exeFile = "temp_exec.exe";
        std::string compileCmd = "g++ " + inputFile + " -o " + exeFile;
        // std::cout << "Compiling " << inputFile << "...\n";
        if (system(compileCmd.c_str()) != 0) {
            std::cerr << "Compilation failed.\n";
            return 1;
        }
    } else {
        exeFile = inputFile;
    }

    // Start wall-clock timer
    auto start = std::chrono::high_resolution_clock::now();

    // Set up process
    STARTUPINFO si = { sizeof(si) };
    PROCESS_INFORMATION pi;
    si.dwFlags |= STARTF_USESTDHANDLES;
    si.hStdInput = GetStdHandle(STD_INPUT_HANDLE);
    si.hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    si.hStdError = GetStdHandle(STD_ERROR_HANDLE);

    if (!CreateProcess(NULL, const_cast<char*>(exeFile.c_str()), NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi)) {
        std::cerr << "Failed to start process.\n";
        return 1;
    }

    WaitForSingleObject(pi.hProcess, INFINITE);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> realTime = end - start;

    // Get CPU times
    FILETIME creationTime, exitTime, kernelTime, userTime;
    GetProcessTimes(pi.hProcess, &creationTime, &exitTime, &kernelTime, &userTime);

    ULARGE_INTEGER uTime, kTime;
    uTime.LowPart = userTime.dwLowDateTime;
    uTime.HighPart = userTime.dwHighDateTime;
    kTime.LowPart = kernelTime.dwLowDateTime;
    kTime.HighPart = kernelTime.dwHighDateTime;

    double userSeconds = uTime.QuadPart / 1e7;
    double sysSeconds = kTime.QuadPart / 1e7;

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    std::cout << std::endl
	      << "user= " << userSeconds << std::endl
              << "sys=  " << sysSeconds << std::endl
              << "real= " << realTime.count() << std::endl;

    return 0;
}
