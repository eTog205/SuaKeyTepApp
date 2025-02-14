﻿//giaodien.h
#pragma once

#include "logic_giaodien.h"

#include <chrono>
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <unordered_map>

struct giaodien
{
	float botron_nen = 10.0f;       // Bán kính bo tròn góc của các khung hiển thị
	float botron_nho = 4.0f;        // Bán kính bo tròn góc của thành phần nhỏ(nút, combo box, ô)

	float chieucao_thanhtieude = 23.0f;

	// Kích thước và vị trí của menu bên
	float chieurong_menuben = 180.0f;        // Chiều rộng menu bên khi mở rộng
	float chieurong_menuben_thugon = 50.0f;  // Chiều rộng menu bên khi thu gọn
	float chieurong_menuben_morong = 180.0f; // Chiều rộng tối đa khi mở rộng menu
	float letrai_menuben = 14.0f;            // Khoảng cách từ lề trái của màn hình đến menu bên
	float letren_menuben = 125.0f;           // Khoảng cách từ lề trên của màn hình đến menu bên
	float chieucao_menuben = 0.0f;           // Chiều cao menu bên (tính theo chiều cao màn hình)

	// Trạng thái thu gọn/mở rộng của menu bên
	bool menuben_thugon = false;       // Biến trạng thái: true nếu menu đang thu gọn
	bool yeucau_thugon = false;        // Biến yêu cầu thu gọn/mở rộng menu
	std::chrono::steady_clock::time_point batdau_thugon = std::chrono::steady_clock::now(); // Thời điểm bắt đầu hiệu ứng thu gọn/mở rộng
	float thoigian_thugon = 0.3f;      // Thời gian hiệu ứng thu gọn/mở rộng menu (giây)

	// Biến dùng trong tìm kiếm và lọc dữ liệu
	char searchBuffer[128] = "";   // Bộ đệm lưu từ khóa tìm kiếm
	int trangthai_hientai = 0;     // Lựa chọn hiện tại của bộ lọc trạng thái
	int phienban_hientai = 0;      // Lựa chọn hiện tại của bộ lọc phiên bản
	int phanloai_hientai = 0;      // Lựa chọn hiện tại của bộ lọc phân loại

	//logic_giaodien lg_gd;
	// Cấu hình hiển thị bảng dữ liệu
	bool hienthi_cot[4] = { true,true,false,true }; // Trạng thái hiển thị của từng cột

	bool hienthi_caidat_cot = false;  // Trạng thái hiển thị menu bật/tắt các cột trong bảng(mặc định: false ẩn lúc ban đầu, true: hiện lên lúc ban đầu)

	// Kích thước và vị trí của bảng dữ liệu
	float chieurong_bang = 0.0f;  // Chiều rộng của bảng dữ liệu
	float letrai_bang = 14.0f;    // Khoảng cách từ lề trái của màn hình đến bảng dữ liệu
	float letren_bang = 125.0f;   // Khoảng cách từ lề trên của màn hình đến bảng dữ liệu
	float chieucao_bang = 0.0f;   // Chiều cao của bảng dữ liệu (tính theo chiều cao màn hình)

	int row_count = 0;

	std::vector<std::vector<std::string>> data;

	std::unordered_map<std::string, bool> selected_map;


};

void handle_collapse(bool& is_collapsed, bool& collapse_requested, const std::chrono::steady_clock::time_point& collapse_start_time, float& current_size, float expanded_size, float collapsed_size, float delay_seconds);

ImVec4 AdjustColorBrightness(const ImVec4& color, float factor);

void giaodien_menuben1(giaodien& gd, bool& hienthi_caidat, ImVec2& vitri_tinhnang, ImVec2& kichthuoc_tinhnang, const int chieucao_manhinh);

void giaodien_caidat(GLFWwindow* cuaSo, bool& hienthi_caidat);

void comboBox_(const char* label, const char* options[], int options_count, int& current_selection, float gt_botron);

void capNhatBangPhanMem(giaodien& gd, const logic_giaodien& lg_gd);

void giaodien_bangdl(giaodien& gd, int chieurong_manhinh, int chieucao_manhinh);

void giaodien_thanhcongcu(giaodien& gd, int chieurong_manhinh, int chieucao_manhinh);
