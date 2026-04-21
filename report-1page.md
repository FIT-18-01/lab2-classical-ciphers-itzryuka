# Report 1 Page – FIT4012 Lab 2

## 1. Mục tiêu
Hiểu nguyên lý và trực tiếp cài đặt hai thuật toán mã hóa cổ điển (Caesar và Rail Fence) bằng ngôn ngữ C++. Thực hành kỹ năng xử lý chuỗi (giữ nguyên khoảng trắng, hỗ trợ cả chữ hoa và chữ thường), kiểm tra tính hợp lệ của dữ liệu đầu vào, thao tác đọc file I/O và làm quen với quy trình quản lý mã nguồn, nộp bài qua nền tảng GitHub.

## 2. Cách làm
- Hoàn thiện Caesar Cipher cho chữ thường, dấu cách và giải mã.
- Hoàn thiện Rail Fence Cipher cho giải mã, giữ dấu cách, kiểm tra đầu vào và đọc file.
- Chạy thử trên nhiều test case.

## 3. Kết quả chính
### 3.1 Caesar Cipher
| Input | Key | Ciphertext / Plaintext | Nhận xét |
|---|---:|---|---|
| I LOVE YOU | 3 | L ORYH BRX | Mã hóa đúng ký tự in hoa, nhận diện và giữ nguyên vị trí của dấu cách (space). |
| hello world | 5 | mjqqt btwqi | Hỗ trợ tốt chữ thường, vòng lặp ký tự (vượt quá 'z' quay vòng lại 'a') chuẩn xác. |
| LORYH BRX | 3 | I LOVE YOU | Hàm giải mã hoạt động chính xác bằng cách tái sử dụng hàm mã hóa với độ dịch (key) âm bù 26. |

### 3.2 Rail Fence Cipher
| Input | Rails | Ciphertext / Plaintext | Nhận xét |
|---|---:|---|---|
| I LOVE YOU | 2 | ILV O OEYU | Thuật toán chia luồng chẵn lẻ chính xác, khoảng trắng được tính là một ký tự bình thường trên lưới. |
| I LOVE YOU | 4 | I  EYLVOOU | Chu kỳ zigzag kéo dài ra, chuỗi bị xáo trộn phức tạp hơn nhiều so với trường hợp 2 rails. |
| IOEOLVYU | 2 | ILOVEYOU | Thuật toán dựng lại thành công ma trận đánh dấu vị trí zigzag và đọc ngược ra plaintext chuẩn xác. |

### 3.3 Input validation / file input
- **Trường hợp đầu vào không hợp lệ:** Khi nhập chuỗi chứa số hoặc ký tự đặc biệt (VD: `hello 123!`), chương trình lập tức bắt lỗi bằng hàm `isalpha()`, in ra thông báo *"Invalid input. Only letters and spaces are allowed."* và kết thúc an toàn.
- **Kết quả đọc từ `data/input.txt`:** Sử dụng `ifstream` đọc thành công dòng dữ liệu từ file văn bản và nạp vào biến message, sau đó thực hiện quá trình mã hóa/giải mã bình thường như khi nhập từ bàn phím.

## 4. Kết luận
Qua bài lab này, em đã nắm vững cách chuyển đổi logic toán học của mã hóa cổ điển vào mã nguồn C++, đặc biệt là thao tác với bảng mã ASCII và mảng 2 chiều (`vector`). Khó khăn lớn nhất là việc xây dựng thuật toán giải mã cho Rail Fence Cipher vì nó yêu cầu phải mô phỏng lại đúng vị trí lưới zigzag ban đầu để điền ký tự từ chuỗi mã hóa. Việc tự tay xử lý vấn đề này giúp em hiểu sâu sắc hơn về bản chất phân phối ký tự của thuật toán thay vì chỉ sử dụng các thư viện có sẵn.

## 5. Tài nguyên đính kèm
*Các tệp tin mã nguồn và dữ liệu liên quan trong Repository:*
- **Source Code:** `src/caesar.cpp`, `src/rail_fence.cpp`
- **Data Input:** `data/input.txt`
- **Testing & Logs:** `tests/test_cases.md`, `logs/run_log.md`
- **Repository:** *[Chèn Link GitHub Repository của bạn vào đây]*