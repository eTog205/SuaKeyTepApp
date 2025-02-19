//logic_giaodien.cpp
#include "chucnang_cotloi.h"
#include "log_nhalam.h"
#include "logic_giaodien.h"

void them_cot(logic_giaodien& lg_gd, const std::string& tenmoi)
{
	if (lg_gd.soluong_cot < lg_gd.succhua)
	{
		// Còn chỗ, chỉ cần thêm vào
		lg_gd.ten_cot[lg_gd.soluong_cot++] = tenmoi;
	} else
	{
		// Hết chỗ, cấp phát lại với kích thước lớn hơn
		const int succhua_moi = lg_gd.succhua * 2;
		const auto temp = new std::string[succhua_moi];

		// Sao chép dữ liệu cũ sang mảng mới
		std::copy_n(lg_gd.ten_cot, lg_gd.soluong_cot, temp);

		delete[] lg_gd.ten_cot;

		// Cập nhật con trỏ và sức chứa mới
		lg_gd.ten_cot = temp;
		lg_gd.succhua = succhua_moi;

		// Thêm cột mới
		lg_gd.ten_cot[lg_gd.soluong_cot++] = tenmoi;
	}
}

void khoitao_logic_giaodien(logic_giaodien& lg_gd)
{
	them_cot(lg_gd, "id", "Tên", "Phân loại");
}

std::string wstring_to_string(const std::wstring& wstr)
{
	if (wstr.empty()) return "";

	const int size_needed = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), static_cast<int>(wstr.size()), nullptr, 0, nullptr, nullptr);
	std::string str(size_needed, 0);
	WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), static_cast<int>(wstr.size()), str.data(), size_needed, nullptr, nullptr);

	return str;
}

std::wstring string_to_wstring(const std::string& str)
{
	if (str.empty()) return L"";

	const int size_needed = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), static_cast<int>(str.size()), nullptr, 0);
	std::wstring wstr(size_needed, 0);
	MultiByteToWideChar(CP_UTF8, 0, str.c_str(), static_cast<int>(str.size()), &wstr[0], size_needed);

	return wstr;
}

float tt_thugonkichthuoc(bool& da_thugon,
						 bool& yeucau_thugon,
						 const std::chrono::steady_clock::time_point& thoigian_batdau_thugon,
						 const float kichthuoc_morong,
						 const float kichthuoc_thugon,
						 const float thoigian_tre)
{
	// Giá trị khởi tạo theo trạng thái hiện tại
	float new_size = da_thugon ? kichthuoc_thugon : kichthuoc_morong;
	if (yeucau_thugon)
	{
		const auto now = std::chrono::steady_clock::now();
		const float elapsed = std::chrono::duration<float>(now - thoigian_batdau_thugon).count();

		float t = std::clamp(elapsed / thoigian_tre, 0.0f, 1.0f);

		const float start_size = da_thugon ? kichthuoc_thugon : kichthuoc_morong;
		const float target_size = da_thugon ? kichthuoc_morong : kichthuoc_thugon;
		new_size = start_size + t * (target_size - start_size);

		if (t >= 1.0f)
		{
			da_thugon = !da_thugon;
			yeucau_thugon = false;
		}
	}

	return new_size;
}


std::string tt_vanbancothenhinthay(const std::wstring& toanbo_vanban,
								   const float chieurong_hientai,
								   const float chieurong_toithieu,
								   const float chieurong_toida)
{
	const float ratio = std::clamp((chieurong_hientai - chieurong_toithieu) / (chieurong_toida - chieurong_toithieu), 0.0f, 1.0f);
	const int max_chars = std::clamp(static_cast<int>(ratio * static_cast<float>(toanbo_vanban.size())), 1, static_cast<int>(toanbo_vanban.size()));
	return wstring_to_string(toanbo_vanban.substr(0, max_chars));
}

void logic_giaodien::chaylenh_winget(const std::string& command_id)
{
	chaylenh(command_id);
}

void logic_giaodien::chaylenh_tienich()
{
	chaylenh_suawindow();
}


