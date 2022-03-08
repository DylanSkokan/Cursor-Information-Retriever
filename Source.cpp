#include <iostream>
#include <windows.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char* argv[])
{
	char guide = 'a';

	int secondDelay = 3;
	if (argv[1] != NULL) {
		secondDelay = atoi(argv[1]);
	}

	while (guide != 'E' && guide != 'e') {
		if (guide == 'C' || guide == 'c') {
			cout << "Enter new delay time:\n";
			cin >> secondDelay;
		}

		Sleep(secondDelay * 1000);

		POINT pos;
		COLORREF color;
		HDC hDC = GetDC(NULL);

		if (GetCursorPos(&pos) && hDC != NULL) {
			cout << "\nX: " << pos.x << ", Y: " << pos.y << "\n";
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
		cout << "\n\nEnter character for action\nC: Change delay time\nE: Exit\n";
		cin >> guide;
	}
}
