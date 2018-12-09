#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    string windowName = "HackMe";
    int address = 0x017DFE1C;

    int oldValue;
    int newValue = 70000;

    HWND hwnd = FindWindowA(nullptr, windowName.c_str());

    if (hwnd == nullptr) {
        cout << "> Cannot find active window named: '" << windowName << "'." << endl;
        Sleep(3000);
        exit(-1);
    } else {
        DWORD processId;
        GetWindowThreadProcessId(hwnd, &processId);
        HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, false, processId);

        if (!processId) {
            cout << "> Cannot obtain process for: '" << windowName << "' window." << endl;
            Sleep(3000);
            exit(-1);
        } else {
            ReadProcessMemory(handle, (PBYTE *) address, &oldValue, sizeof(oldValue), nullptr);
            WriteProcessMemory(handle, (LPVOID) address, &newValue, sizeof(newValue), nullptr);
            cout << "> Changed value from: " << oldValue << " to " << newValue << endl;
            Sleep(3000);
        }
    }

    return 0;
}
