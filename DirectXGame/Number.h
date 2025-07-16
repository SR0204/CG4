#pragma once
#include <KamataEngine.h>

class Number {

public:
	Number();

	~Number();

	void Initialize();

	void Update();

	void Draw();

private:
	uint32_t textureHandle_;

	std::vector<KamataEngine::Sprite*> NumberSprite_;
	const KamataEngine::Vector2 size = {20, 20}; // 各数字のサイズ
	const KamataEngine::Vector2 startPos = {200, 50}; // 右上の開始位置
};
