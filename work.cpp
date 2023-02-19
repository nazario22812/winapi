#include <Windows.h>



LRESULT CALLBACK SoftwareMainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON hIcon, LPCWSTR Name, WNDPROC Procedure);
LRESULT CALLBACK SoftwareMainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);



int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
	WNDCLASS SoftClass = NewWindowClass((HBRUSH)COLOR_WINDOW, LoadCursor(NULL, IDC_ARROW), hInst, LoadIcon(hInst, IDI_QUESTION), L"MainWndClass", SoftwareMainProcedure);

    if (!RegisterClassW(&SoftClass)) {
        return -1;
    }
    MSG SoftwareMainMessage = { 0 };

    CreateWindow(L"MainWndClass", L"First c++ window", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 500, 250, NULL, NULL, NULL, NULL); //��������� ���� ����

    /* ������ ������� ���� ����*/
    while (GetMessage(&SoftwareMainMessage, NULL, NULL, NULL)) {
        TranslateMessage(&SoftwareMainMessage);
        DispatchMessage(&SoftwareMainMessage);
    }

    return 0;


}  

WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON hIcon, LPCWSTR Name, WNDPROC Procedure) {
    WNDCLASS WC = { 0 };

    WC.hIcon = hIcon;
    WC.hCursor = Cursor;
    WC.hInstance = hInst;
    WC.lpszClassName = Name;
    WC.hbrBackground = BGColor;
    WC.lpfnWndProc = Procedure;

    return WC;
}

LRESULT CALLBACK SoftwareMainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg){
    
    case WM_CREATE:
        break;

    case WM_DESTROY:
        PostQuitMessage(0); //��������� ����
        break;

    default: return DefWindowProc(hWnd, msg, wp, lp);
    }
}


void AddWidgets(HWND hWnd) {

}