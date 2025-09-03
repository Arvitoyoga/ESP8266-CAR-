# ESP8266-CAR-

/*
=====================================================================
Program WiFi Car dengan ESP8266
=====================================================================


Program ini digunakan untuk mengendalikan mobil berbasis ESP8266 
melalui koneksi WiFi. ESP8266 akan mencoba terhubung ke WiFi router 
(Station Mode). Jika gagal, ESP8266 akan otomatis membuat Access Point 
(AP Mode) dengan SSID "WIFI CAR". Perintah kontrol mobil dikirim 
melalui koneksi HTTP (web server port 80).

Konfigurasi Pin (Motor Driver):
- in1 (GPIO15 / D8) : Motor kiri maju.
- in2 (GPIO13 / D7) : Motor kiri mundur.
- in3 (GPIO12 / D6) : Motor kanan maju.
- in4 (GPIO14 / D5) : Motor kanan mundur.

Fitur Utama:
1. **Koneksi WiFi Ganda**
   - Mode Station (STA) → mencoba koneksi ke router dengan SSID & password.
   - Mode Access Point (AP) → jika gagal, ESP8266 membuat hotspot sendiri.

2. **Kontrol Mobil via HTTP**
   - Perintah dikirim dalam bentuk string:
     - "maju"   → mobil maju.
     - "mundur" → mobil mundur.
     - "kanan"  → mobil belok kanan.
     - "kiri"   → mobil belok kiri.
     - "stop"   → mobil berhenti.

3. **Web Server**
   - ESP8266 menjalankan server di port 80.
   - Client (HP/Laptop) mengirim request HTTP untuk mengendalikan mobil.

Tujuan:
- Membuat sistem mobil robot sederhana berbasis IoT.
- Memberikan fleksibilitas kontrol melalui WiFi (bisa STA/AP).
- Memanfaatkan server HTTP untuk komunikasi ringan dengan ESP8266.
*/
