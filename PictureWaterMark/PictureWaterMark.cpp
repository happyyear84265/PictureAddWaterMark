// PictureWaterMark.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include "atlimage.h"

using namespace std;


int main()
{
    BLENDFUNCTION bf = { 0 };
    bf.BlendOp = AC_SRC_OVER;
    bf.BlendFlags = 0;
    bf.AlphaFormat = 0;
    bf.SourceConstantAlpha = 25;
    CImage img;
    img.Load(L"1.jpg");
    HDC dc1 = img.GetDC();

    CImage m_image3;
    m_image3.Create(100, 100, 32);
    HDC dc2 = m_image3.GetDC();
    TextOut(dc2,10,10,L"test",lstrlen(L"test"));
    TextOut(dc2, 20, 20, L"test1", lstrlen(L"test1"));
    TextOut(dc2, 30, 30, L"test2", lstrlen(L"test2"));
    TextOut(dc2, 40, 40, L"test3", lstrlen(L"test3"));
    //直接貼上方式，會被覆蓋
    //BitBlt(m_image3.GetDC(), 0, 0, img.GetWidth(), img.GetHeight(), img.GetDC(), 0, 0, SRCCOPY);
    
    //雙方混和方式，顏色會較暗淡
    AlphaBlend(dc1, 0, 0, img.GetWidth(), img.GetHeight(), dc2, 0, 0, m_image3.GetWidth(), m_image3.GetHeight(), bf);

    img.Save(L"2.jpg");

    ReleaseDC(0,dc1);
    ReleaseDC(0, dc2);
    img.Destroy();
    m_image3.Destroy();
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
