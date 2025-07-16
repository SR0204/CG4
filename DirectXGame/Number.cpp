#include "Number.h"

using namespace KamataEngine;

Number::Number() {}

Number::~Number() {}

void Number::Initialize() {
	textureHandle_ = TextureManager::Load("./Resources/number.png");

	auto Numbersprite = KamataEngine::Sprite::Create(textureHandle_, startPos);
	Numbersprite->SetSize(size);

	for (int i = 0; i < 5; i++) {
		Numbersprite = Sprite::Create(textureHandle_, {100.0f + size.x * i, 5});
	}
	NumberSprite_.push_back(Numbersprite);
}

void Number::Update() {

	for (int i = 0; i < NumberSprite_.size(); i++) {
		NumberSprite_[i]->SetTextureRect({startPos.x}, {startPos.y});
	}
}

void Number::Draw() {
	for (int i = 0; i < 5; i++) {
		NumberSprite_[i]->Draw();
	}
}