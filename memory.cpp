#include <iostream>
#include <Windows.h>

int main()
{
    // Placeholder offsets for demonstration purposes
    DWORD baseAddress = 0x12345678;
    DWORD healthOffset = 0x100;
    DWORD ammoOffset = 0x200;

    // Get the process ID of the game
    DWORD processId;
    HWND hwnd = FindWindowA(NULL, "Postal 2");
    GetWindowThreadProcessId(hwnd, &processId);

    // Open the process
    HANDLE processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processId);
    if (processHandle == NULL)
    {
        std::cout << "Failed to open the process!" << std::endl;
        return 1;
    }

    // Calculate the address of the health variable
    DWORD healthAddress = baseAddress + healthOffset;

    // Read the current health value
    int currentHealth;
    ReadProcessMemory(processHandle, (LPCVOID)healthAddress, &currentHealth, sizeof(int), NULL);

    // Modify the health value
    int newHealth = currentHealth + 100;
    WriteProcessMemory(processHandle, (LPVOID)healthAddress, &newHealth, sizeof(int), NULL);

    // Calculate the address of the ammo variable
    DWORD ammoAddress = baseAddress + ammoOffset;

    // Read the current ammo value
    int currentAmmo;
    ReadProcessMemory(processHandle, (LPCVOID)ammoAddress, &currentAmmo, sizeof(int), NULL);

    // Modify the ammo value
    int newAmmo = currentAmmo + 50;
    WriteProcessMemory(processHandle, (LPVOID)ammoAddress, &newAmmo, sizeof(int), NULL);

    // Close the process handle
    CloseHandle(processHandle);

    std::cout << "Memory hack complete!" << std::endl;

    return 0;
}
