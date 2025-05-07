#include "Effect.h"

void Effect::Initialize(Model* model) {

	// NULLポインタチェック
	// assert(model_);

	model_ = model;

	worldTransform_.Initialize();
}

void Effect::Update() {
	
	// 行列を定数バッファに転送
	worldTransform_.TransferMatrix();
}

void Effect::Draw(Camera& camera) {
	// 3Dモデルを描画
	model_->Draw(worldTransform_, camera);
}
