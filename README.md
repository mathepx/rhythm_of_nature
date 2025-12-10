# rhythm_of_nature
transferring electrosignals to rhthms and waves
Bu proje, bitkilerin ve mantarların elektriksel iletkenlik değişimlerini (Galvanik Tepki) ölçerek, bu verileri Arduino aracılığıyla anlamlı müzik notalarına dönüştürür.

## 🛠 Kullanılan Malzemeler
* Arduino Uno
* 3.3M Ohm Direnç
* Jumper Kablolar ve Timsah Klipsler
* Bilgisayar (MIDI Yazılımı için)
* Canlı Denek: Mantar veya Saksı Bitkisi

## ⚙️ Nasıl Çalışır?
1. **Sensör:** Bitki, devrede değişken bir direnç görevi görür.
2. **İşleme:** Arduino, bitkiden gelen mikro voltaj değişimlerini okur.
3. **Çıktı:** Yazılımımız bu veriyi analiz eder ve MIDI sinyallerine çevirerek bilgisayara gönderir.

## 💻 Kurulum
Projenin çalışması için `Hairless MIDI` ve `LoopMIDI` programları gereklidir.
