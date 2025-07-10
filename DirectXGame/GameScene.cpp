#include "GameScene.h"
#include <cmath>
using namespace KamataEngine;

GameScene::GameScene() {}

GameScene::~GameScene() {
	
}

void GameScene::Initialize() {

	
}

void GameScene::Update() {

	
}

void GameScene::Draw() {
	// DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();
	// スプライト描画前処理
	Sprite::PreDraw(dxCommon->GetCommandList());


	// スプライト描画後処理
	Sprite::PostDraw();
}