#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct House{
    char location[30];
    char city[30];
    int price;
    int room;
    int bathroom;
    int carpark;
    char type[30];
    char furnish[30];
};

int jumlah_baris(FILE *file){
    char buffer[9999];
    int counter = 0;
    while(fgets(buffer, 9999, file)){
        counter++;
    }
    fseek(file, 0, SEEK_SET);
    return counter;
}

void isi_house(FILE *file, struct House house[], int jumlah_struct){
    char buffer[9999];
    fgets(buffer, sizeof(buffer), file);

    for(int i = 0; i < jumlah_struct; i++){
        char oneline[9999];
        fgets(oneline, sizeof(oneline), file);
    
        sscanf(oneline, "%[^,],%[^,],%d,%d,%d,%d,%[^,],%[^\n]",
            house[i].location, 
            house[i].city, 
            &house[i].price, 
            &house[i].room, 
            &house[i].bathroom, 
            &house[i].carpark, 
            house[i].type, 
            house[i].furnish
        );
    }
}

void display(struct House house[], int rows){
    system("cls");

    printf("%-25s %-15s %-10s %-7s %-9s %-8s %-10s %-10s\n",
       "Location", "City", "Price", "Rooms",
       "Bathroom", "Carpark", "Type", "Furnish");

    for(int i = 0; i < rows; i++){
        printf("%-25s %-15s %-10d %-7d %-9d %-8d %-10s %-10s\n",
        house[i].location, 
        house[i].city, 
        house[i].price, 
        house[i].room, 
        house[i].bathroom, 
        house[i].carpark, 
        house[i].type, 
        house[i].furnish);
    }
};

void display_once(struct House house){
        printf("%-25s %-15s %-10d %-7d %-9d %-8d %-10s %-10s\n",
        house.location, 
        house.city, 
        house.price, 
        house.room, 
        house.bathroom, 
        house.carpark, 
        house.type, 
        house.furnish);
}

int validasi_nama_kolom(char input[]){
    if(strcasecmp(input, "Location") == 0 ||
        strcasecmp(input, "City") == 0 ||
        strcasecmp(input, "Price") == 0 ||
        strcasecmp(input, "Rooms") == 0 ||
        strcasecmp(input, "Bathroom") == 0 ||
        strcasecmp(input, "Carpark") == 0 ||
        strcasecmp(input, "Type") == 0 ||
        strcasecmp(input, "Furnish") == 0
    ){
        return 1;
    }else{
        return 0;
    }
}

void search(struct House house[], int jumlah_baris, char str_column[], char search[]){
    system("cls");

    int flag_data_ada = 0;

    //loop ngecek datanya ditemukan atau tidak
    if (strcasecmp(str_column, "Location") == 0){
        for(int i = 0; i < jumlah_baris; i++){
            if(strcasecmp(search, house[i].location) == 0){
                flag_data_ada++;
            }
        }

    } else if (strcasecmp(str_column, "City") == 0){
        for(int i = 0; i < jumlah_baris; i++){
            if(strcasecmp(search, house[i].city) == 0){
                flag_data_ada++;
            }
        }

    } else if (strcasecmp(str_column, "Price") == 0){
        int price = atoi(search);
        for(int i = 0; i < jumlah_baris; i++){
            if(price == house[i].price){
                flag_data_ada++;
            }
        }

    } else if (strcasecmp(str_column, "Rooms") == 0){
        int room = atoi(search);
        for(int i = 0; i < jumlah_baris; i++){
            if(room == house[i].room){
                flag_data_ada++;
            }
        }

    } else if (strcasecmp(str_column, "Bathroom") == 0){
        int bath = atoi(search);
        for(int i = 0; i < jumlah_baris; i++){
            if(bath == house[i].bathroom){
                flag_data_ada++;
            }
        }

    } else if (strcasecmp(str_column, "Carpark") == 0){
        int car = atoi(search);
        for(int i = 0; i < jumlah_baris; i++){
            if(car == house[i].carpark){
                flag_data_ada++;
            }
        }

    } else if (strcasecmp(str_column, "Type") == 0){
        for(int i = 0; i < jumlah_baris; i++){
            if(strcasecmp(search, house[i].type) == 0){
                flag_data_ada++;
            }
        }

    } else if (strcasecmp(str_column, "Furnish") == 0){
        for(int i = 0; i < jumlah_baris; i++){
            if(strcasecmp(search, house[i].furnish) == 0){
                flag_data_ada++;
            }
        }

    } else {
        printf("Tolong masukkan nama kolom yang benar\n");
        return;
    }

    //print datanya
    if(flag_data_ada == 0){
        printf("Data not found!\n");
        return;
    }

    printf("Data found. Detail of data:\n");
    printf("%-25s %-15s %-10s %-7s %-9s %-8s %-10s %-10s\n",
       "Location", "City", "Price", "Rooms",
       "Bathroom", "Carpark", "Type", "Furnish");

    if (strcasecmp(str_column, "Location") == 0){
        for(int i = 0; i < jumlah_baris; i++){
            if(strcasecmp(search, house[i].location) == 0){
                display_once(house[i]);
            }
        }

    } else if (strcasecmp(str_column, "City") == 0){
        for(int i = 0; i < jumlah_baris; i++){
            if(strcasecmp(search, house[i].city) == 0){
                display_once(house[i]);
            }
        }

    } else if (strcasecmp(str_column, "Price") == 0){
        int price = atoi(search);
        for(int i = 0; i < jumlah_baris; i++){
            if(price == house[i].price){
                display_once(house[i]);
            }
        }

    } else if (strcasecmp(str_column, "Rooms") == 0){
        int room = atoi(search);
        for(int i = 0; i < jumlah_baris; i++){
            if(room == house[i].room){
                display_once(house[i]);
            }
        }

    } else if (strcasecmp(str_column, "Bathroom") == 0){
        int bath = atoi(search);
        for(int i = 0; i < jumlah_baris; i++){
            if(bath == house[i].bathroom){
                display_once(house[i]);
            }
        }

    } else if (strcasecmp(str_column, "Carpark") == 0){
        int car = atoi(search);
        for(int i = 0; i < jumlah_baris; i++){
            if(car == house[i].carpark){
                display_once(house[i]);
            }
        }

    } else if (strcasecmp(str_column, "Type") == 0){
        for(int i = 0; i < jumlah_baris; i++){
            if(strcasecmp(search, house[i].type) == 0){
                display_once(house[i]);
            }
        }

    } else if (strcasecmp(str_column, "Furnish") == 0){
        for(int i = 0; i < jumlah_baris; i++){
            if(strcasecmp(search, house[i].furnish) == 0){
                display_once(house[i]);
            }
        }

    }

}

void sort(struct House house[], int jumlah_baris, char str_column[], char sort[]){
    system("cls");

    //sortingnya
    if(strcasecmp(str_column, "Location") == 0){

        if(strcasecmp(sort, "asc") == 0){
            for(int i = 0; i < jumlah_baris - 1; i++){
                for(int j = i+1; j < jumlah_baris; j++){
                    if(strcasecmp(house[j].location, house[i].location) < 0) {
                        struct House temp = house[i];
                        house[i] = house[j];
                        house[j] = temp;
                    }
                }
            }
        }else{
            for(int i = 0; i < jumlah_baris - 1; i++){
                for(int j = i+1; j < jumlah_baris; j++){
                    if(strcasecmp(house[j].location, house[i].location) > 0) {
                        struct House temp = house[i];
                        house[i] = house[j];
                        house[j] = temp;
                    }
                }
            }
        }

    }else if(strcasecmp(str_column, "City") == 0){

        if(strcasecmp(sort, "asc") == 0){
            for(int i = 0; i < jumlah_baris - 1; i++){
                for(int j = i+1; j < jumlah_baris; j++){
                    if(strcasecmp(house[j].city, house[i].city) < 0) {
                        struct House temp = house[i];
                        house[i] = house[j];
                        house[j] = temp;
                    }
                }
            }
        }else{
            for(int i = 0; i < jumlah_baris - 1; i++){
                for(int j = i+1; j < jumlah_baris; j++){
                    if(strcasecmp(house[j].city, house[i].city) > 0) {
                        struct House temp = house[i];
                        house[i] = house[j];
                        house[j] = temp;
                    }
                }
            }
        }

    }else if(strcasecmp(str_column, "Price") == 0){
        
        if(strcasecmp(sort, "asc") == 0){
            for(int i = 0; i < jumlah_baris - 1; i++){
                for(int j = i+1; j < jumlah_baris; j++){
                    if(house[j].price < house[i].price) {
                        struct House temp = house[i];
                        house[i] = house[j];
                        house[j] = temp;
                    }
                }
            }
        }else{
            for(int i = 0; i < jumlah_baris - 1; i++){
                for(int j = i+1; j < jumlah_baris; j++){
                    if(house[j].price > house[i].price) {
                        struct House temp = house[i];
                        house[i] = house[j];
                        house[j] = temp;
                    }
                }
            }
        }

    }else if(strcasecmp(str_column, "Rooms") == 0){

        if(strcasecmp(sort, "asc") == 0){
            for(int i = 0; i < jumlah_baris - 1; i++){
                for(int j = i+1; j < jumlah_baris; j++){
                    if(house[j].room < house[i].room) {
                        struct House temp = house[i];
                        house[i] = house[j];
                        house[j] = temp;
                    }
                }
            }
        }else{
            for(int i = 0; i < jumlah_baris - 1; i++){
                for(int j = i+1; j < jumlah_baris; j++){
                    if(house[j].room > house[i].room) {
                        struct House temp = house[i];
                        house[i] = house[j];
                        house[j] = temp;
                    }
                }
            }
        }

    }else if(strcasecmp(str_column, "Bathroom") == 0){

        if(strcasecmp(sort, "asc") == 0){
            for(int i = 0; i < jumlah_baris - 1; i++){
                for(int j = i+1; j < jumlah_baris; j++){
                    if(house[j].bathroom < house[i].bathroom) {
                        struct House temp = house[i];
                        house[i] = house[j];
                        house[j] = temp;
                    }
                }
            }
        }else{
            for(int i = 0; i < jumlah_baris - 1; i++){
                for(int j = i+1; j < jumlah_baris; j++){
                    if(house[j].bathroom > house[i].bathroom) {
                        struct House temp = house[i];
                        house[i] = house[j];
                        house[j] = temp;
                    }
                }
            }
        }

    }else if(strcasecmp(str_column, "Carpark") == 0){

        if(strcasecmp(sort, "asc") == 0){
            for(int i = 0; i < jumlah_baris - 1; i++){
                for(int j = i+1; j < jumlah_baris; j++){
                    if(house[j].carpark < house[i].carpark) {
                        struct House temp = house[i];
                        house[i] = house[j];
                        house[j] = temp;
                    }
                }
            }
        }else{
            for(int i = 0; i < jumlah_baris - 1; i++){
                for(int j = i+1; j < jumlah_baris; j++){
                    if(house[j].carpark > house[i].carpark) {
                        struct House temp = house[i];
                        house[i] = house[j];
                        house[j] = temp;
                    }
                }
            }
        }

    }else if(strcasecmp(str_column, "Type") == 0){

        if(strcasecmp(sort, "asc") == 0){
            for(int i = 0; i < jumlah_baris - 1; i++){
                for(int j = i+1; j < jumlah_baris; j++){
                    if(strcasecmp(house[j].type, house[i].type) < 0) {
                        struct House temp = house[i];
                        house[i] = house[j];
                        house[j] = temp;
                    }
                }
            }
        }else{
            for(int i = 0; i < jumlah_baris - 1; i++){
                for(int j = i+1; j < jumlah_baris; j++){
                    if(strcasecmp(house[j].type, house[i].type) > 0) {
                        struct House temp = house[i];
                        house[i] = house[j];
                        house[j] = temp;
                    }
                }
            }
        }

    }else if(strcasecmp(str_column, "Furnish") == 0){

        if(strcasecmp(sort, "asc") == 0){
            for(int i = 0; i < jumlah_baris - 1; i++){
                for(int j = i+1; j < jumlah_baris; j++){
                    if(strcasecmp(house[j].furnish, house[i].furnish) < 0) {
                        struct House temp = house[i];
                        house[i] = house[j];
                        house[j] = temp;
                    }
                }
            }
        }else{
            for(int i = 0; i < jumlah_baris - 1; i++){
                for(int j = i+1; j < jumlah_baris; j++){
                    if(strcasecmp(house[j].furnish, house[i].furnish) > 0) {
                        struct House temp = house[i];
                        house[i] = house[j];
                        house[j] = temp;
                    }
                }
            }
        }

    }

    printf("Data found. Detail of data:\n");
    printf("%-25s %-15s %-10s %-7s %-9s %-8s %-10s %-10s\n",
       "Location", "City", "Price", "Rooms",
       "Bathroom", "Carpark", "Type", "Furnish");
    
    for(int i = 0; i < jumlah_baris; i++){
        display_once(house[i]);
    }
}

void export(FILE *file, struct House house[], int jumlah_baris, char nama_file[]){

    strcat(nama_file, ".csv");
    
    file = fopen(nama_file, "w");
    if(file == NULL){
        printf("Gagal membuat file silahkan cek lokasi file\n");
        return;
    }

    fprintf(file, "Location 1,Location 2,Price,Rooms,Bathrooms,CarParks,Type,Furnish\n");
    for(int i = 0; i < jumlah_baris; i++){
        fprintf(file, "%s,%s,%d,%d,%d,%d,%s,%s\n",
            house[i].location, 
            house[i].city, 
            house[i].price, 
            house[i].room, 
            house[i].bathroom, 
            house[i].carpark, 
            house[i].type, 
            house[i].furnish
        );
    }
    printf("Data successfully written to file %s!\n", nama_file);
    fclose(file);
}


int main(){

    FILE *fp = fopen("data.csv", "r");
    if(fp == NULL){
        printf("Gagal membuka file silahkan cek lokasi file\n");
        return 0;
    }

    int jumlah_baris_file = jumlah_baris(fp) - 1; // -1 karena header nggak di hitung
    struct House house[jumlah_baris_file];

    isi_house(fp, house, jumlah_baris_file);

    fclose(fp);


    while(1){
        //Display
        system("cls");
        printf("What do you want to do?\n");
        printf("1. Display data\n");
        printf("2. Search Data\n");
        printf("3. Sort Data\n");
        printf("4. Export Data\n");
        printf("5. Exit\n");


        char i[5];
        printf("Your choice: ");
        fgets(i, sizeof(i), stdin);
        i[strcspn(i, "\n")] = '\0';
        int input = atoi(i);

        if(input == 1){

            while(1){

                char str_rows[99];
                int rows;
                printf("Number of rows: ");
                fgets(str_rows, sizeof(str_rows), stdin);
                str_rows[strcspn(str_rows, "\n")] = '\0';
                rows = atoi(str_rows);
                if(rows <= 0){
                    printf("Input hanya berupa angka (1-9)\n");
                    continue;
                }
                
                //panggil fungsinya
                display(house, rows);
                printf("press [Enter]\n");
                getchar();
                break;

            }

        }else if(input == 2){

            while(1){

                char str_column[99];
                printf("Choose column: ");
                fgets(str_column, sizeof(str_column), stdin);
                str_column[strcspn(str_column, "\n")] = '\0';

                if(validasi_nama_kolom(str_column) == 0){
                    printf("Masukan nama kolom dengan benar!\n");
                    continue;
                }
                
                char yang_di_search[99];
                printf("What data do you want to find? ");
                fgets(yang_di_search, sizeof(yang_di_search), stdin);
                yang_di_search[strcspn(yang_di_search, "\n")] = '\0';

                //panggil fungsinya
                search(house, jumlah_baris_file, str_column, yang_di_search);
                printf("press [Enter]\n");
                getchar();
                break;

            }

        }else if(input == 3){

            while(1){

                char str_column[99];
                printf("Choose column: ");
                fgets(str_column, sizeof(str_column), stdin);
                str_column[strcspn(str_column, "\n")] = '\0';

                if(validasi_nama_kolom(str_column) == 0){
                    printf("Masukan nama kolom dengan benar!\n");
                    continue;
                }
                
                char yang_di_sort[99];
                printf("Sort ascending or descending? ");
                fgets(yang_di_sort, sizeof(yang_di_sort), stdin);
                yang_di_sort[strcspn(yang_di_sort, "\n")] = '\0';

                if(strcasecmp(yang_di_sort, "asc") != 0 && strcasecmp(yang_di_sort, "des") != 0 ){
                    printf("Input hanya berupa (asc/des)\n");
                    continue;
                }

                //panggil fungsinya
                sort(house, jumlah_baris_file, str_column, yang_di_sort);
                printf("press [Enter]\n");
                getchar();
                break;

            }
        }else if(input == 4){

            char nama_file[99];
            printf("File name: ");
            fgets(nama_file, sizeof(nama_file), stdin);
            nama_file[strcspn(nama_file, "\n")] = '\0';

            //panggil fungsinya
            export(fp, house, jumlah_baris_file, nama_file);
            printf("press [Enter]\n");
            getchar();
            continue;

        }else if(input == 5){
            break;
        }else{
            printf("Input hanya tersedia(1-5)\n");
            continue;
        }
    }




    // printf("jumlah baris -1 header: %d\n", jumlah_baris_file);

    // for(int i = 0; i < jumlah_baris_file; i++){
    //     printf("%s,%s,%d,%d,%d,%d,%s,%s\n",
    //         house[i].location, house[i].city, house[i].price, house[i].room, house[i].bathroom, house[i].carpark, house[i].type, house[i].furnish
    //     );
    // }

    
    return 0;
}