*Bu proje 42 müfredatının bir parçası olarak ademirel tarafından oluşturulmuştur.*
# Get Next Line
## Açıklama (Description)

    Bu projenin temel amacı, bir dosya tanımlayıcıdan (file descriptor) okunan metni satır satır döndüren bir fonksiyon yazmaktır. Proje, C programlamada bellek yönetimi, dosya okuma işlemleri ve özellikle statik değişkenlerin (static variables) kullanımı konusundaki yetkinliği artırmayı hedefler. get_next_line fonksiyonu her çağrıldığında, okunan dosyanın bir sonraki satırını (satır sonu karakteri dahil) döndürür.
## Talimatlar (Instructions)
Derleme

    Proje, standart cc derleyicisi ve -Wall -Wextra -Werror bayrakları ile derlenmelidir. Ayrıca, okuma tamponu boyutunu belirlemek için -D BUFFER_SIZE=n bayrağının eklenmesi gerekmektedir.

    Örnek derleme komutu:

    cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl

## Kullanım ve Kurallar

    Girdi: Fonksiyon hem normal dosyalardan hem de standart girdiden (stdin) okuma yapabilmektedir.

    Dönüş Değeri: Okunan satırı döndürür; okunacak bir şey kalmadığında veya hata oluştuğunda NULL döndürür.

    Kısıtlamalar: libft kullanımı, lseek() fonksiyonu ve küresel (global) değişken kullanımı yasaktır.

## Kaynaklar ve Yapay Zeka Kullanımı (Resources)

    Referanslar: C Programlama dili belgeleri, read, malloc ve free fonksiyonlarının man sayfaları.

    Yapay Zeka Beyanı: Bu projede yapay zeka araçları; readme dosyasının hazırlanması, temel algoritmik yapıların mantığını kavramak ve hata ayıklama süreçlerinde fikir alışverişi yapmak amacıyla kullanılmıştır. Kodun tamamı, 42 AI kurallarına uygun olarak , mantığı kavranarak ve manuel olarak yazılmıştır; doğrudan kod kopyalama yapılmamıştır.

## Algoritma Seçimi ve Açıklaması

Bu projede kullanılan algoritma, verimlilik ve minimum okuma prensibine dayanmaktadır:

    Tamponlama: Her çağrıda BUFFER_SIZE kadar veri okunur ve bir statik değişkende saklanır.

    Satır Kontrolü: Statik değişken içindeki veride bir satır sonu karakteri (\n) olup olmadığı kontrol edilir.

    Parçalama: Eğer satır sonu bulunursa, o kısma kadar olan veri kullanıcıya döndürülür; geri kalan kısım bir sonraki çağrı için statik değişkende tutulmaya devam eder.

    Dinamik Bellek: Okunan verileri birleştirmek için malloc kullanılır ve sızıntıları önlemek amacıyla her işlem sonunda gerekli free işlemleri yapılır.