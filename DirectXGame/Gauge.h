#pragma once
#include <2d/Sprite.h>
#include <KamataEngine.h>

class Gauge {

public:
	Gauge();

	~Gauge();

	void Initialize();

	void Update();

	void Draw();

private:
	KamataEngine::Sprite* hpBack_ = nullptr;    // 背景（グレー）
	KamataEngine::Sprite* hpOld_ = nullptr;     // 緑：ディレイHP
	KamataEngine::Sprite* hpCurrent_ = nullptr; // 赤：現在HP
	float hpRate_ = 1.0f;                       // 現在のHP割合
	float hpOldRate_ = 1.0f;                    // ディレイ表示用のHP割合

	uint32_t textureHandle_;
};
