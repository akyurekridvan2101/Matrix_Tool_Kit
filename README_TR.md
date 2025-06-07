# Matris İşlemleri Programı

Bu program, kare matrisler üzerinde çeşitli işlemler gerçekleştiren bir C programıdır. Programın temel özellikleri ve kullanım talimatları aşağıda açıklanmıştır.

## Kullanım

1. **Başlatma:**
   - Program, kullanıcıdan bir kare matrisin boyutunu (`matrix_size`) girmesini isteyerek başlar.

2. **Matris Oluşturma:**
   - Kullanıcıya, matris elemanlarını manuel olarak girme veya belirtilen bir aralıkta rastgele değerlerle doldurma seçeneği sunulur.

3. **Üst Üçgensel Matrise Dönüştürme:**
   - `upperTriangularize` fonksiyonu, girilen matrisi üst üçgensel forma dönüştürür.

4. **Matrisleri Ekrana Yazdırma:**
   - `printMatrix` fonksiyonu, orijinal matrisi ve üst üçgensel matrisi ekrana yazdırır.

5. **Determinant Hesaplama:**
   - `calcDet` fonksiyonu, üst üçgensel matrisin determinantını hesaplar.

6. **Cramer Yöntemi ile Denklem Çözümü:**
   - `solveUsingCramer` fonksiyonu, Cramer yöntemiyle denklem çözümleri yapar ve sonuçları ekrana yazdırır.

7. **Matris İzi Hesaplama ve Transpoz Alma:**
   - Program, matrisin izini hesaplar ve transpozunu alarak sonuçları ekrana yazdırır.

8. **Bellek Temizleme:**
   - Bellek sızıntılarını önlemek için kullanılan bellek program sonunda serbest bırakılır.

## Kurulum

Projeyi kullanmak için aşağıdaki adımları takip edebilirsiniz:

1. Depoyu klonlayın: `git clone https://github.com/akyurekridvan2101/Matrix-tool-kit.git`
2. Proje dizinine gidin: `cd MATRIX-TOOL-KIT/"Matrix tool kit"`
3. Programı derleyin: `gcc matrixToolKit.c -o matrix_tool_kit`
4. Programı çalıştırın: `./matrix_tool_kit`

## Video

https://github.com/akyurekridvan2101/Matrix-tool-kit/assets/98421577/c9fe3b01-9f21-4344-b903-cc71bb7a9ec5

## Uyarı: Taşma (Overflow) Durumları

Bu program, matris boyutları veya elemanları çok büyük olduğunda `long int` veri tipinin sınırlarının aşılabileceğine dair bir uyarı içerir. Özellikle `long int` değer sınırını aşan sayılarla çalışırken doğru sonuçlar alınamayabilir.

Matris boyutu veya elemanları çok büyükse, programın sonuçlarına güvenmek yerine matris boyutunu ve elemanlarını mümkün olduğunca küçük tutmak daha güvenilir olabilir. Ayrıca, programın giriş ve çıkışlarının dikkatlice kontrol edilmesi önemlidir.

Eğer bir matrisin boyutu veya elemanları çok büyükse ve beklenmeyen sonuçlar elde edilirse, bu durumu düzeltmek için matrisin boyutu ve elemanları küçültülebilir veya farklı bir yöntemle çözüm aranabilir.

