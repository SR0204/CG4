#include "Particle.h"

using namespace MathUtility;

void Particle::Initialize(Model* model, Vector3 posistion) {

	// NULLポインタチェック
	// assert(model_);

	model_ = model;

	worldTransform_.Initialize();
	worldTransform_.translation_ = posistion;

	// 色の設定
	objectColor_.Initialize();
	color_ = {1, 0, 1, 1};
}

void Particle::Update() {

	// 移動
	worldTransform_.translation_ += {0.0f, 0.1f, 0.0f};

	// 行列の更新
	worldTransform_.UpdateMatrix();

	// 色変更オブジェクトに色の数値を設定する
	objectColor_.SetColor(color_);
}

void Particle::Draw(Camera& camera) {

	// 3Dモデルを描画
	model_->Draw(worldTransform_, camera, &objectColor_);
}
