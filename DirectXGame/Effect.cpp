#include "Effect.h"
using namespace MathUtility;

void Effect::Initialize(Model* model, Vector3 rotation, Vector3 velocity) {

	// NULLポインタチェック
	// assert(model_);

	model_ = model;
	velocity_ = velocity;

	worldTransform_.Initialize();

	worldTransform_.rotation_ = rotation;
	// 大きさ
	worldTransform_.scale_ = {0.1f, 6.0f, 0.0f};
	
}

void Effect::Update() {
	// 回転
	worldTransform_.rotation_ += {velocity_.x, velocity_.y, 0};

	// 行列の更新
	worldTransform_.UpdateMatrix();
}

void Effect::Draw(Camera& camera) {
	// 3Dモデルを描画
	model_->Draw(worldTransform_, camera);
}
