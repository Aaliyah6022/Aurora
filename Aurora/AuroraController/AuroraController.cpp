#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <memory>
#include <string_view>
#include <cstdint>
#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include <random>

#pragma warning(disable : C26815)

using namespace std;

HWND hWnd = nullptr;
unsigned long processId, threadId = 0;

uintptr_t moduleBase;

uintptr_t localPlayer;
uintptr_t entList;
uintptr_t viewRenderer;
uintptr_t viewMatrix;

std::string random_string(const int len) {
	const std::string alpha_numeric("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890");

	std::default_random_engine generator{ std::random_device{}() };
	const std::uniform_int_distribution< std::string::size_type > distribution{ 0, alpha_numeric.size() - 1 };

	std::string str(len, 0);
	for (auto& it : str) {
		it = alpha_numeric[distribution(generator)];
	}

	return str;
}

int main()
{
	// random console name
	LPCSTR name = random_string(24).c_str();
	SetConsoleTitle(name);

	if (hWnd != NULL)
	{
		hWnd = FindWindow(NULL, "Calculator.exe");
		cout << "[+] Found Apex!" << endl;
	}
	else
	{
		cout << "[+] Apex not launched!" << endl;
	}

	if (processId != NULL)
	{
		threadId = GetWindowThreadProcessId(hWnd, &processId);
		std::cout << "threadId: " << threadId << std::endl;
		std::cout << "processId: " << processId << std::endl;
	}
	else
	{
		cout << "[+] Could not find process!" << endl;
	}

	// loop function
	while (true)
	{

	}
}
