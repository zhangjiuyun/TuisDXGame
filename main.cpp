#include "DxLib.h" /* DXライブラリという宴旋な�C嬬を聞うため */
int main() {

	int x = 640/2-32/2, y = 480/2-32/2; /* �篳�の傚冱 */
	int keyInput;

	int bg = 0;
	int myShip = 0;

	int speed = 5;//speed setter

	myShip = LoadGraph("MyShip32.bmp");
	bg = LoadGraph("bg.jpg");

	SetDrawScreen(DX_SCREEN_BACK);  /* 宙鮫枠を�Y鮫中に�O協する */

	while (1) { /* �o�泙棒Rり卦す(�o�泪覃`プ) */

		ClsDrawScreen(); /* 宙鮫枠鮫中をきれいに��肇する */

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

		ScreenFlip(); /* �Y鮫中に宙鮫したものを燕鮫中に��亟する */


		if (CheckHitKey(KEY_INPUT_ESCAPE)) break; /* エスケ�`プキ�`が兀されたら�Rり卦し�I尖から竃る */
	} /* while( )の�]じ嶄凄察 */

	return 0;
}
