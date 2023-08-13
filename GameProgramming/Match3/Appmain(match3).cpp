
//マッチ3制作

#include "DxLib.h"
#include "FreamControl.h"
#include "InputControl.h"
#include "SceneManager.h"

//マクロ定義

#define SCREEN_HEIGHT (480)　　　　//スクリーンサイズ（高さ）
#define SCREEN_WIDTH (640)　　　　 //スクリーンサイズ（幅）
#define SCREEN_COLORBIT (32)　　　 //スクリーンカラービット　　
#define FONT_SIZE (20)             //文字サイズ

//型定義

//グローバル変換宣言

//プロトタイプ宣言

//プログラムの開始

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//ウィンドウタイトル設定

	SetMainWindowText("Match 3 Puzzle");

	//ウィンドウモードで起動

	ChangeWindowMode(TRUE);

	//画面サイズの最大サイズ、カラービット数を設定

	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLORBIT);


	//Dxライブラリ初期化処理

	//エラーが発生したら、終了する

	if (DxLib_Init() == D_ERROR)
	{
		return D_ERROR;
	}

	//各機能の初期化処理

	FreamControl_Initialize();
	Input_Initialize();

	//シーンマネージャー初期化処理

	//エラーが発生したら、終了する

	if (SceneManager_Initialize(E_TITLE) == D_ERROR)
	{
		return D_ERROR;
	}

	//描画先画面を裏にする

	SetDrawScreen(DX_SCREEN_BACK);

	//文字サイズを設定

	SetFontSize(FONT_SIZE);

	//ゲームループ

	while (ProcessMessage() != D_ERROR && Input_Escape() == FALSE)
	{
		//入力制御機能更新処理

		Input_Update();

		//シーンマネージャー描画処理

		SceneManager_Update();

		//画面クリア

		ClearDrawScreen();

		//シーンマネージャー描画処理

		SceneManager_Draw();

		//フレームレート制御処理

		FreamControl_Update();

		//画面の内容を表画面に反映

		ScreenFlip();

	}
	//Dxライブラリ使用の終了処理

	DxLib_End();

	return 0;

}