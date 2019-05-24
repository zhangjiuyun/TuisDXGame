#include "DxLib.h" /* DXライブラリという便利な機能を使うため */
int main() {

	int x = 640/2-32/2, y = 480/2-32/2; /* 変数の宣言 */
	int keyInput;

	int bg = 0;
	int myShip = 0;

	int speed = 5;//speed setter

	myShip = LoadGraph("MyShip32.bmp");
	bg = LoadGraph("bg.jpg");

	SetDrawScreen(DX_SCREEN_BACK);  /* 描画先を裏画面に設定する */

	while (1) { /* 無限に繰り返す(無限ループ) */

		ClsDrawScreen(); /* 描画先画面をきれいに消去する */

		keyInput = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		if (keyInput == PAD_INPUT_RIGHT) {
			if ((x + speed) >= (639 - 31))x = (639 - 31);
			else x += speed;
		}
		if (keyInput == PAD_INPUT_LEFT) {
			if ((x - speed) <= 0)x = 0;
			else x -= speed;
		}
		if (keyInput == PAD_INPUT_DOWN) {
			if ((y + speed) >= (479 - 31))y = (479 - 31);
			else y += speed;
		}
		if (keyInput == PAD_INPUT_UP) {
			if ((y - speed) <= 0)y = 0;
			else y -= speed;
		}

		DrawGraph(0, 0, bg, TRUE);

		DrawGraph(x, y, myShip, TRUE);

		ScreenFlip(); /* 裏画面に描画したものを表画面に転写する */


		if (CheckHitKey(KEY_INPUT_ESCAPE)) break; /* エスケープキーが押されたら繰り返し処理から出る */
	} /* while( )の閉じ中括弧 */

	return 0;
}
