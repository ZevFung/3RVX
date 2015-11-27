#include "HotkeyInput.h"

#include "../../3RVX/Logger.h"
#include "../Controls/Controls.h"
#include "KeyGrabber.h"

HotkeyInput::HotkeyInput() :
Dialog(L"3RVX-HotkeyInput", MAKEINTRESOURCE(IDD_HOTKEYPROMPT)) {
    ShowWindow(Dialog::Handle(), SW_SHOWNORMAL);
    _cancel = new Button(BTN_CANCELKEYS, *this);
    _cancel->OnClick = [this]() {
        return true;
    };


}


INT_PTR HotkeyInput::DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_INITDIALOG:
        KeyGrabber::Instance()->SetHwnd(hwndDlg);
        KeyGrabber::Instance()->Grab();
        break;

    case WM_CLOSE:
//        CLOG(L"Closing hotkey prompt.");
//        EnableWindow(_parent, TRUE);
//        EndDialog(hwndDlg, 0);
//        DestroyWindow(_hWnd);
        break;

    case WM_COMMAND:
//        nCode = HIWORD(wParam);
//        ctrlId = LOWORD(wParam);
//        if (ctrlId == BTN_CANCEL && nCode == BN_CLICKED) {
//            SendMessage(hwndDlg, WM_CLOSE, NULL, NULL);
//        }
        break;
    }

    return Dialog::DialogProc(hwndDlg, uMsg, wParam, lParam);
}