/*
  TÜBİTAK 4006 - Biyo-Sonifikasyon (Kararlı Sürüm v2)
  Sorun Çözümü: Sürekli ötme engellendi (Senaryo B)
  Yöntem: Dinamik Eşik Değeri (Dynamic Threshold)
*/

const int buzzerPin = 8;
const int sensorPin = A0;

int anlikDeger = 0;
int oncekiDeger = 0;

// HASSASİYET AYARI (Burası Çok Önemli)
// Eğer hala kendi kendine ötüyorsa bu sayıyı büyüt (örn: 50, 80 yap)
// Eğer dokununca ses çıkmıyorsa bu sayıyı küçült (örn: 10, 5 yap)
int esikDegeri = 100; 

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  // Açılışta ilk değeri alalım
  oncekiDeger = analogRead(sensorPin);
}

void loop() {
  // 1. Veriyi Oku
  anlikDeger = analogRead(sensorPin);
  
  // 2. Grafikte görmek için yazdır (Seri Çiziciyi açınca izle)
  // Mavi çizgi: Sinyal, Kırmızı çizgi: Tetiklenme Sınırı
  Serial.print("Sinyal:");
  Serial.print(anlikDeger);
  Serial.print(",Sabit:"); // Grafiğin ölçeği bozulmasın diye referans
  Serial.println(500); 

  // 3. KARAR ANI: Değişim var mı?
  // Şu anki değer, bir önceki değerden 'esikDegeri' kadar farklı mı?
  int degisim = abs(anlikDeger - oncekiDeger);
  
  if (degisim > esikDegeri) {
    // ANİ DEĞİŞİM (DOKUNMA) ALGILANDI!
    
    // Rastgele güzel bir nota üret (Pentatonik Skala)
    int notalar[] = {262, 330, 392, 494, 523, 600, 650, 700, 750, 800, 850, 900, 950, 1000, 1100, 1150, 1175, 1200}; // Do, Mi, Sol, Si, İnce Do
    int rasgeleNota = notalar[random(0, 5)];
    
    tone(buzzerPin, rasgeleNota);
    delay(100); // Sesin duyulması için süre
  } else {
    // Değişim yoksa veya çok azsa SUS
    noTone(buzzerPin);
  }

  // 4. Hafızayı Güncelle
  // Şu anki değeri "önceki" yap ki bir sonraki turda buna göre kıyaslayalım.
  // Hafif bir filtreleme ile güncelle (Smoothing)
  oncekiDeger = anlikDeger; 
  
  delay(50); // Ölçümler arası bekleme
}