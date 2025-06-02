# Matrix Operations Program

Bu program, kare matrisler üzerinde çeşitli işlemleri gerçekleştiren bir C programıdır. Programın temel özellikleri ve kullanım talimatları aşağıda açıklanmıştır.

## Kullanım

1. **Başlangıç:**
   - Program, kullanıcıdan bir kare matrisin boyutunu girmesini isteyerek başlar (`matrix_size`).

2. **Matris Oluşturma:**
   - Kullanıcıya, matris elemanlarını manuel olarak girmek veya belirli bir aralık içinde rastgele değerlerle doldurmak seçeneği verilir.

3. **Üst Üçgensel Matrise Dönüştürme:**
   - `upperTriangularize` fonksiyonu, giriş matrisini üst üçgensel bir forma dönüştürür.

4. **Matrisleri Ekrana Yazdırma:**
   - `printMatrix` fonksiyonu, başlangıç ​​matrisini ve üst üçgensel matrisi ekrana yazdırır.

5. **Determinant Hesaplama:**
   - `calcDet` fonksiyonu, üst üçgensel matrisin determinantını hesaplar.

6. **Cramer Yöntemiyle Denklemleri Çözme:**
   - `solveUsingCramer` fonksiyonu, denklemleri Cramer yöntemiyle çözer ve sonuçları ekrana yazdırır.

7. **Matris İzi Hesaplama ve Transpoz Alma:**
   - Program, matris izini hesaplar ve matrisin transpozunu alır, sonuçları ekrana yazdırır.

8. **Bellek Temizleme:**
   - Program, bellek sızıntılarını önlemek için kullanılan belleği serbest bırakır.

## Kurulum

Projeyi kullanmak için aşağıdaki adımları izleyebilirsiniz:

1. Depoyu klonlayın: `git clone https://github.com/akyurekridvan2101/Matrix-tool-kit.git`
2. Proje dizinine gidin: `cd MATRIX-TOOL-KIT/"Matrix tool kit"`
3. Programı derleyin: `gcc matrixToolKit.c -o matrix_tool_kit`
4. Programı çalıştırın: `./matrix_tool_kit`

## Görseller

Buraya programın ekran görüntülerini ekleyebilirsiniz:

![Ekran Görüntüsü 1](images/screenshot1.png)
*Programın ana ekranı*

![Ekran Görüntüsü 2](images/screenshot2.png)
*Matris oluşturma işlemi*

## Video

Aşağıda programın kullanımını gösteren bir video ekleyebilirsiniz:

[![Program Kullanımı](https://img.youtube.com/vi/VIDEO_ID_HERE/0.jpg)](https://www.youtube.com/watch?v=VIDEO_ID_HERE)
*Programın kullanımını gösteren video*

Lütfen "VIDEO_ID_HERE" kısmını gerçek video ID'siyle değiştirin ve uygun olan şekilde bağlantıyı düzenleyin. Videoyu barındırdığınız platforma göre bu Markdown kodunu uygun şekilde düzenleyebilirsiniz.

## Uyarı: Taşma Olabilecek Durumlar

Bu program, matris boyutları veya matris elemanları çok büyük olduğunda `long int` boyutunda taşmaların olabileceği bir uyarı içerir. Özellikle `long int` boyutunu aşan değerlerle çalışıldığında doğru sonuçlar alınamayabilir.

Matris boyutları veya elemanları çok büyük olduğunda, programın sonuçlarına güvenmek yerine matris boyutunu ve elemanlarını mümkün olduğunca küçük tutmak daha güvenilir olabilir. Ayrıca, girdilerin doğruluğunu ve programın çıktılarını dikkatlice kontrol etmek önemlidir.

Bir matrisin boyutu veya elemanları çok büyükse ve beklenmeyen sonuçlar alıyorsanız, matris boyutunu ve elemanlarını azaltarak veya farklı bir yöntemle problemi çözerek bu durumu düzeltebilirsiniz.

