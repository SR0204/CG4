#pragma once
#include "KamataEngine.h"

class Stage {
public:
	Stage();
	~Stage();

	void Initialize();
	void Update();
	void Draw();

private:
	uint32_t textureHandle_;
	KamataEngine::Sprite* sprite1_;
	KamataEngine::Sprite* sprite2_;

	float scrollX_ = 0.0f;
	float scrollSpeed_ = 2.0f;
	float bgWidth_ = 1280;
};
