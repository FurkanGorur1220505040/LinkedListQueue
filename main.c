#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int data;
    struct Queue *next;
};

struct Queue *front = NULL; // Kuyrugun baþini gosteren isaretci
struct Queue *rear = NULL;  // Kuyrugun sonunu gosteren isaretci

// Kuyruga eleman ekleme fonksiyonu
void EnQueue(int a) {
    struct Queue *gecici = (struct Queue*) malloc(sizeof(struct Queue));   // Yeni bir dügüm olusturulur
    gecici->data = a;      // Dugumun veri kismina deger atanir
    gecici->next = NULL;  // Dugumun next isaretcisi bos olarak ayarlanir
    
    if (front == NULL && rear == NULL) // Kuyruk bos ise, hem front hem de rear yeni dugumu gosterir 
	{
    
        front = rear = gecici;
    }
	 else // Kuyruk dolu ise, yeni dugum rear dugumunun next isaretcisini gosterir ve rear guncellenir
	{
        rear->next = gecici;
        rear = gecici;
    }
}
// Kuyruktan eleman cýkarma fonksiyonu
void Dequeue() {
    struct Queue *gecici = front;  // cikarilacak dugum front dugumunu gosterir
  
    if (front == rear) 	// Kuyrukta tek bir dugum varsa, kuyruk bosaltilir
    	{
		
        front = rear = NULL;
    }
	 else 
	 // Kuyrukta birden fazla dugum varsa, front dugumu guncellenir
	{
        front = front->next;
    }
    free(gecici); // cikarilan dugum bellekten serbest birakilir
}

// Kuyrugu goruntuleme fonksiyonu
void Print() {
    struct Queue *gecici = front;   // Gecici bir isaretci front dugumunu gosterir
    while (gecici != NULL) {
        printf("%d ", gecici->data);  // Dugumun veri kismi yazdirilir
        gecici = gecici->next;   
    }
    printf("\n");
}

int main() {
    int secenek, deger;
    while (1) {
        printf("\n1.Eleman Ekle\n2.Eleman Sil\n3.Listeyi Goruntule\n4.Cikis\n");
        printf("Seciminiz:");
        scanf("%d", &secenek);
        switch (secenek) {
            case 1:
                printf("Eklenecek elemani girin: ");
                scanf("%d", &deger);
                EnQueue(deger);
                break;
            case 2:
                printf("Silinecek elemani girin: ");
                scanf("%d", &deger);
                Dequeue(deger);
                break;
            case 3:
                Print();
                break;
            case 4:
                exit(0);
            default:
                printf("Gecersiz secim.\n");
        }
    }
    return 0;
}

