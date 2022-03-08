#include <iostream>
#include <windows.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char* argv[])
{
	char exit = 'n';

	int secondDelay = 3;
	if (argv[1] != NULL) {
		secondDelay = atoi(argv[1]);
	}

	while (exit != 'Y' && exit != 'y') {

		Sleep(secondDelay * 1000);

		POINT pos;
		COLORREF color;
		HDC hDC = GetDC(NULL);

		if (GetCursorPos(&pos) && hDC != NULL) {
			cout << "X: " << pos.x << ", Y: " << pos.y << "\n";
			color = GetPixel(hDC, pos.x, pos.y);
			ReleaseDC(GetDesktopWindow(), hDC);
			printf("R: %i, G: %i, B: %i", GetRValue(color), GetGValue(color), GetBValue(color));
		}
		else if (!GetCursorPos(&pos) && hDC == NULL) {
			cout << "Failed to get cursor position and handle device context.";
		}
		else if (!GetCursorPos(&pos)) {
			cout << "Failed to get cursor position.";
		}
		else if (hDC == NULL) {
			cout << "Failed to handle device context.";
		}
		cout << "\nExit?\n";
		cin >> exit;
	}
}