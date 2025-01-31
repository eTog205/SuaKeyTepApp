#pragma once

//#include <boost/asio/ip/tcp.hpp>
//#include <boost/asio/ssl/context.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/ssl.hpp>
#include <nlohmann/json.hpp>
#include <string>

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
using tcp = net::ip::tcp;

// 🔹 Khóa AES và IV cố định (phải giữ bí mật)
constexpr unsigned char key[17] = "my_secret_key_16";
constexpr unsigned char iv[18] = "initial_vector_iv";

struct csdl
{
    std::string owner = "eTog205";
    std::string repo = "SuaKeyTepApp";
    std::string file_path = "cauhinh_pm_ht.json";
    std::string sha_file = "cauhinh_pm_ht.sha";
};

// 🔹 Hàm giải mã AES-128-CBC
std::string decrypt_aes(const std::string& ciphertext);

// 🔹 Đọc token từ `config.dat` (giải mã AES)
std::string load_token();

// 🔹 Hàm giải mã Base64 nếu cần
std::string decode_base64(const std::string& encoded);

// 🔹 Hàm gửi request HTTP GET
std::string send_http_request(const std::string& host, const std::string& target, const std::string& token);

// 🔹 Hàm lấy nội dung `data.json` từ GitHub API
std::string fetch_github_data(const std::string& owner, const std::string& repo, const std::string& file_path, const std::string& token);

std::string fetch_github_file_metadata(const std::string& owner, const std::string& repo, const std::string& file_path, const std::string& token);

// 🔹 Hàm lưu nội dung ra file
void save_to_file(const std::string& filename, const std::string& data);

// 🔹 Hàm lưu sha ra file
void luu_tepsha(const std::string& sha_file, const std::string& owner, const std::string& repo, const std::string& file_path, const std::string& decrypted_token);

void capnhat_data();