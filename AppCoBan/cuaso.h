﻿#pragma once
#include <GLFW/glfw3.h>


// Định nghĩa cấu trúc dữ liệu cho cấu hình
struct CauHinhCuaSo
{
	int chieurong; // Chiều rộng của cửa sổ
	int chieucao;  // Chiều cao của cửa sổ
	const char* tieude; // Tiêu đề của cửa sổ

	enum chedo_hienthi : uint8_t
	{
		cuaso, toan_manhinh, khongvien
	} chedo; // Chế độ hiển thị

	// Hàm tạo cấu hình mặc định
	static CauHinhCuaSo macdinh()
	{
		return { 1024, 700, "Tông", cuaso };
	}
};

inline CauHinhCuaSo cauhinh_cuaso = CauHinhCuaSo::macdinh();
