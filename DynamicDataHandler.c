#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{

	char *name;
	int numbers;
	int rank;


}Person;

//Flagleri ayırma islemlerini yapıyor.Dosyaları extra(optinal) flagleri  dogru bir sekilde kaydediyor.Dosyaları okurken segmentation fault hatası  veriyor. 

void islem_yap(char *first_flag, char *target_name ,char *dosya_isimleri[10],char *extra_flags);

int flag_mi(char *c);
int main(int argc, char *argv[]){


    int dosya_sayac=0;
    char *a;
	a=(char *)malloc(sizeof(char)*5);
    char *first_flag;
	first_flag=(char *)malloc(sizeof(char)*5);//first flag
    char *b;
	b=(char *)malloc(sizeof(char)*5);// second check argument.
	
    char *c;
    c=(char *)malloc(sizeof(char)*5);	//third check argument  extra flags


    char *extraflags;
    extraflags=(char *)malloc(sizeof(char)*5);
    char *dosya_isimleri[10];
	for(int i=0;i<10;i++){
		dosya_isimleri[i]=(char *)malloc(sizeof(char)*30);
	}
    char *target_name;
	target_name=(char *)malloc(sizeof(char)*5);

    char *extra_seperated_flags[3];
	
	for(int i=0;i<10;i++){
		extra_seperated_flags[i]=(char *)malloc(sizeof(char)*5);
	}

    char *birlestirilmis;
	birlestirilmis=(char *)malloc(sizeof(char)*5);
    char *birlestirilmis1;
	birlestirilmis1=(char *)malloc(sizeof(char)*5);
    int i=0;


    if(argc==1){
	printf("There is no argument on command line\n");
	exit(1);

    }else{
	first_flag=argv[1];

	if(strcmp(first_flag,"-s")==0){
	

		if(argc>2){
			b=argv[2];

			if(b[0]=='-'){
				printf("You should enter a target_name not a flag.\n");
				exit(1);			

			}else{
			
				target_name=argv[2];
				if(argc>3){
				
					c=argv[3];
					   if(flag_mi(c)==0){
						if(strcmp(c,"-npr")==0||strcmp(c,"-nrp")==0||strcmp(c,"-prn")==0||strcmp(c,"-pnr")==0||strcmp(c,"-rpn")==0||strcmp(c,"-rn")==0||strcmp(c,"-nr")==0
									||strcmp(c,"-rp")==0||strcmp(c,"-pr")==0||strcmp(c,"-pn")==0||strcmp(c,"-np")==0 ){
			
							strcpy(extraflags,c);//burada dosya isimlerinini alınması lazım.
							int sayac=0;
							for(int i=4;i<argc;i++){
								c=argv[i];								
										
								strcpy(dosya_isimleri[dosya_sayac],argv[i]);
								dosya_sayac++;
								islem_yap(first_flag,target_name,dosya_isimleri,extraflags);
									


							}						
							

						}else{
							int sayac=0;
							for(int i=3;i<argc;i++){
								c=argv[i];								
								if(flag_mi(c)==0){
									extra_seperated_flags[sayac]=c;//bunlardan sonra eger flags yoksa hep dosya ismi olacagını varsayıyoruz.
									sayac++;			//yani araya bir daha flag giremez..		

								}else{
									if(sayac==1){
										strcpy(extraflags,extra_seperated_flags[0]);
										strcpy(dosya_isimleri[dosya_sayac],argv[i]);
										dosya_sayac++;
										islem_yap(first_flag,target_name,dosya_isimleri,extraflags);
									}else if(sayac==2){
										strcat(extra_seperated_flags[0],extra_seperated_flags[1]);
										strcpy(birlestirilmis,extra_seperated_flags[0]);
										strcpy(dosya_isimleri[dosya_sayac],argv[i]);
										dosya_sayac++;
										islem_yap(first_flag,target_name,dosya_isimleri,birlestirilmis);	
									}else if(sayac==3){
										strcat(extra_seperated_flags[0],extra_seperated_flags[1]); 
										strcpy(birlestirilmis,extra_seperated_flags[0]);
										strcat(birlestirilmis,extra_seperated_flags[2]);
										strcpy(birlestirilmis1,birlestirilmis);										
										strcpy(dosya_isimleri[dosya_sayac],argv[i]);
										dosya_sayac++;	
										islem_yap(first_flag,target_name,dosya_isimleri,birlestirilmis1);	
									}


								}


							}
					
						}					
					
					
					   }else{
						strcpy(extraflags,"-rnp");//default
						//dosya isimleri burada arancak. 4ten baslancak
						for(int i=3;i<argc;i++){
							strcpy(dosya_isimleri[dosya_sayac],argv[i]);
							islem_yap(first_flag,target_name,dosya_isimleri,"-rnp");
			
							dosya_sayac++;
						}
				
					   }	


				}else{
					printf("Wrong.You should enter a file name or extra flags -r -n -p \n");
					exit(1);				

				}
	
			}

		}else{
			printf("you should enter a target_name\n");
			exit(1);


		}


	
	
	}else if(strcmp(first_flag,"-v")==0){
		//printf("Esit\n");
		if(argc>2){
			b=argv[2];

			if(b[0]=='-'){
				printf("You should enter a target_name not a flag.\n");
				exit(1);			

			}else{
			
				target_name=argv[2];
				if(argc>3){
				
					c=argv[3];
					   if(flag_mi(c)==0){
						if(strcmp(c,"-npr")==0||strcmp(c,"-nrp")==0||strcmp(c,"-prn")==0||strcmp(c,"-pnr")==0||strcmp(c,"-rpn")==0||strcmp(c,"-rn")==0||strcmp(c,"-nr")==0
									||strcmp(c,"-rp")==0||strcmp(c,"-pr")==0||strcmp(c,"-pn")==0||strcmp(c,"-np")==0 ){
			
							strcpy(extraflags,c);//burada dosya isimlerinini alınması lazım.
							int sayac=0;
							for(int i=4;i<argc;i++){
								c=argv[i];								
										
								strcpy(dosya_isimleri[dosya_sayac],argv[i]);
								dosya_sayac++;
								islem_yap(first_flag,target_name,dosya_isimleri,extraflags);
									


							}						
							

						}else{
							int sayac=0;
							for(int i=3;i<argc;i++){
								c=argv[i];								
								if(flag_mi(c)==0){
									extra_seperated_flags[sayac]=c;//bunlardan sonra eger flags yoksa hep dosya ismi olacagını varsayıyoruz.
									sayac++;			//yani araya bir daha flag giremez..		

								}else{
									if(sayac==1){
										strcpy(extraflags,extra_seperated_flags[0]);
										strcpy(dosya_isimleri[dosya_sayac],argv[i]);
										dosya_sayac++;
										islem_yap(first_flag,target_name,dosya_isimleri,extraflags);
									}else if(sayac==2){
										strcat(extra_seperated_flags[0],extra_seperated_flags[1]);
										strcpy(birlestirilmis,extra_seperated_flags[0]);
										strcpy(dosya_isimleri[dosya_sayac],argv[i]);
										dosya_sayac++;
										islem_yap(first_flag,target_name,dosya_isimleri,birlestirilmis);	
									}else if(sayac==3){
										strcat(extra_seperated_flags[0],extra_seperated_flags[1]); 
										strcpy(birlestirilmis,extra_seperated_flags[0]);
										strcat(birlestirilmis,extra_seperated_flags[2]);
										strcpy(birlestirilmis1,birlestirilmis);										
										strcpy(dosya_isimleri[dosya_sayac],argv[i]);
										dosya_sayac++;	
										islem_yap(first_flag,target_name,dosya_isimleri,birlestirilmis1);	
									}


								}


							}
					
						}					
					
					
					   }else{
						strcpy(extraflags,"-rnp");//default
						//dosya isimleri burada arancak. 4ten baslancak
						for(int i=3;i<argc;i++){
							strcpy(dosya_isimleri[dosya_sayac],argv[i]);
							islem_yap(first_flag,target_name,dosya_isimleri,"-rnp");
			
							dosya_sayac++;
						}
				
					   }	


				}else{
					printf("Wrong.You should enter a file name or extra flags -r -n -p \n");
					exit(1);
				}
	
			}

		}else{
			printf("you should enter a target_name\n");
			exit(1);


		}


	}else{
		printf("Wrong.You should start  with -s or -v.\n");
		exit(1);
	

	}


   }

	/*
	printf("%s\n",target_name);
	printf("%s\n",extraflags);
	printf("%s\n",first_flag);
	for(int i=0;i<10;i++)
		printf("%s\n",dosya_isimleri[i]);


	printf("%s\n",birlestirilmis);
	printf("%s\n",birlestirilmis1);
*/

}


void islem_yap(char *first_flag, char *target_name ,char *dosya_isimleri[10],char *extra_flags){

	
	Person *male;
	Person *female;
	
	int dosya_sayisi=0;	
	for(int i=0;i<10;i++){
		if(strcmp(dosya_isimleri[i],"+")!=0){
			dosya_sayisi++;
		}	
	}
	
	
	int size=0;
	
	FILE *file;
	for(int i=0;i<dosya_sayisi;i++){
		int size=0;		
		file=fopen(dosya_isimleri[i], "r");
	
		if(file==NULL){
			printf("Dosya acmada hata.\n");
		
		}	
		

		male=(Person *)malloc(sizeof(Person)*1000);


		female=(Person *)malloc(sizeof(Person)*1000);
	
	
		for(int i=0;i<100;i++){

			(male+i)->name=(char*)malloc(sizeof(char)*50);

		}
	
	
		for(int i=0;i<100;i++){

			(female+i)->name=(char*)malloc(sizeof(char)*50);

		}
	
	
	   	

	 	while(1)
		{
		
			if( fscanf(file , "%d %s %d %s %d" ,  &((male+size)->rank),  (male+size)->name ,  &((male+size)->numbers), (female+size)->name,  &((female+size)->numbers)) ==EOF)
				break;

			((female+size))->rank=((male+size))->rank;
		

			size++;
		
		}
		printf("%s file\n",dosya_isimleri[i]);
	
		fclose(file);
		if( strcmp(first_flag,"-s")==0 && strcmp(extra_flags,"-rnp")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strcmp( (male+i)->name,target_name)==0){

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strcmp( (female + i)->name,target_name)==0){
				
					sayi= (female+i)->numbers;
					trank=(female+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;

					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				printf("%s rank:%d\n",target_name,trank);
				printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				printf("percentage%.10f\n",yuzde);				

			}	



		

		}else if( strcmp(first_flag,"-s")==0 && strcmp(extra_flags,"-npr")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strcmp( (male+i)->name,target_name)==0){

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strcmp( (female + size)->name,target_name)==0){
				
					sayi= (female+i)->numbers;
					trank=(female+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;

					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				printf("%s rank:%d\n",target_name,trank);
				printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				printf("percentage%.10f\n",yuzde);				
				sayi=0;
				trank=0;

			}	



		
		}else if( strcmp(first_flag,"-s")==0 && strcmp(extra_flags,"-nrp")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strcmp( (male+i)->name,target_name)==0){

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strcmp( (female + i)->name,target_name)==0){
				
					sayi= (female+i)->numbers;
					trank=(female+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;

					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				printf("%s rank:%d\n",target_name,trank);
				printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				printf("percentage%.10f\n",yuzde);				
				sayi=0;
				trank=0;

			}	



		}else if( strcmp(first_flag,"-s")==0 && strcmp(extra_flags,"-prn")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strcmp( (male+i)->name,target_name)==0){

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strcmp( (female + i)->name,target_name)==0){
				
					sayi= (female+i)->numbers;
					trank=(female+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;

					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				printf("%s rank:%d\n",target_name,trank);
				printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				printf("percentage%.10f\n",yuzde);				
				sayi=0;
				trank=0;

			}	



		}else if( strcmp(first_flag,"-s")==0 && strcmp(extra_flags,"-pnr")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strcmp( (male+i)->name,target_name)==0){

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strcmp( (female + i)->name,target_name)==0){
				
					sayi= (female+i)->numbers;
					trank=(female+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;

					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				printf("%s rank:%d\n",target_name,trank);
				printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				printf("percentage%.10f\n",yuzde);				
				sayi=0;
				trank=0;

			}	



		}else if( strcmp(first_flag,"-s")==0 && strcmp(extra_flags,"-rpn")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strcmp( (male+i)->name,target_name)==0){

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strcmp( (female + i)->name,target_name)==0){
				
					sayi= (female+i)->numbers;
					trank=(female+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;

					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				printf("%s rank:%d\n",target_name,trank);
				printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				printf("percentage%.10f\n",yuzde);				
				sayi=0;
				trank=0;

			}	



		}else if( strcmp(first_flag,"-s")==0 && strcmp(extra_flags,"-rn")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strcmp( (male+i)->name,target_name)==0){

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strcmp( (female + i)->name,target_name)==0){
				
					sayi= (female+i)->numbers;
					trank=(female+i)->rank;
				}

				
				
					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				printf("%s rank:%d\n",target_name,trank);
				printf("%snumber:%d\n",target_name,sayi);			
				
			}	



		}else if( strcmp(first_flag,"-s")==0 && strcmp(extra_flags,"-nr")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strcmp( (male+i)->name,target_name)==0){

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strcmp( (female + i)->name,target_name)==0){
				
					sayi= (male+i)->numbers;
					trank=(female+i)->rank;
				}

				
				
					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				printf("%s rank:%d\n",target_name,trank);
				printf("%snumber:%d\n",target_name,sayi);			
				
			}	


		}else if( strcmp(first_flag,"-s")==0 && strcmp(extra_flags,"-rp")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strcmp( (male+i)->name,target_name)==0){

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strcmp( (female + i)->name,target_name)==0){
				
					sayi= (female+i)->numbers;
					trank=(female+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;

					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				printf("%s rank:%d\n",target_name,trank);
				//printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				printf("percentage.%10f\n",yuzde);				
				sayi=0;
				trank=0;

			}	



		}else if( strcmp(first_flag,"-s")==0 && strcmp(extra_flags,"-pr")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strcmp( (male+i)->name,target_name)==0){

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strcmp( (female + i)->name,target_name)==0){
				
					sayi= (female+i)->numbers;
					trank=(female+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;

					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				printf("%s rank:%d\n",target_name,trank);
				//printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				printf("percentage %.10f\n",yuzde);				
				sayi=0;
				trank=0;

			}	



		}else if( strcmp(first_flag,"-s")==0 && strcmp(extra_flags,"-pn")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strcmp( (male+i)->name,target_name)==0){

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strcmp( (female + i)->name,target_name)==0){
				
					sayi= (female+i)->numbers;
					trank=(male+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;

					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				//printf("%s rank:%d\n",target_name,trank);
				printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				printf("percentage%.10f\n",yuzde);				
				sayi=0;
				trank=0;

			}	



		}else if( strcmp(first_flag,"-s")==0 && strcmp(extra_flags,"-np")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strcmp( (male+i)->name,target_name)==0){

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strcmp( (female + i)->name,target_name)==0){
				
					sayi= (female+i)->numbers;
					trank=(male+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;


					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				//printf("%s rank:%d\n",target_name,trank);
				printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				printf("percentage%.10f\n",yuzde);				
				sayi=0;
				trank=0;

			}	



		}else if( strcmp(first_flag,"-s")==0 && strcmp(extra_flags,"-n-p")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strcmp( (male+i)->name,target_name)==0){

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strcmp( (female + i)->name,target_name)==0){
				
					sayi= (female+i)->numbers;
					trank=(male+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;

					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				//printf("%s rank:%d\n",target_name,trank);
				printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				printf("percentage%.10f\n",yuzde);				
				sayi=0;
				trank=0;

			}	



		}else if( strcmp(first_flag,"-s")==0 && strcmp(extra_flags,"-p-n")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strcmp( (male+i)->name,target_name)==0){

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strcmp( (female + i)->name,target_name)==0){
				
					sayi= (female+i)->numbers;
					trank=(male+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;

					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				//printf("%s rank:%d\n",target_name,trank);
				printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				printf("percentage%.10f\n",yuzde);				
				sayi=0;
				trank=0;

			}	



		}else if( strcmp(first_flag,"-s")==0 && strcmp(extra_flags,"-p-r")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strcmp( (male+i)->name,target_name)==0){

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strcmp( (female + i)->name,target_name)==0){
				
					sayi= (female+i)->numbers;
					trank=(male+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;

					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				printf("%s rank:%d\n",target_name,trank);
				//printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				printf("percentage %.10f\n",yuzde);				
				sayi=0;
				trank=0;

			}	



		}else if( strcmp(first_flag,"-s")==0 && strcmp(extra_flags,"-r-p")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strcmp( (male+i)->name,target_name)==0){

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strcmp( (female + i)->name,target_name)==0){
				
					sayi= (female+i)->numbers;
					trank=(male+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;

					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				printf("%s rank:%d\n",target_name,trank);
				//printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				printf("percentage.%10f\n",yuzde);				
				sayi=0;
				trank=0;

			}	



		}else if( strcmp(first_flag,"-s")==0 && strcmp(extra_flags,"-n-r")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strcmp( (male+i)->name,target_name)==0){

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strcmp( (female + i)->name,target_name)==0){
				
					sayi= (female+i)->numbers;
					trank=(male+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;


				
				
					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				printf("%s rank:%d\n",target_name,trank);
				printf("%snumber:%d\n",target_name,sayi);			
				
			}	


		}else if( strcmp(first_flag,"-s")==0 && strcmp(extra_flags,"-r-n")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strcmp( (male+i)->name,target_name)==0){

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strcmp( (female + i)->name,target_name)==0){
				
					sayi= (female+i)->numbers;
					trank=(male+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;

				
				
					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				printf("%s rank:%d\n",target_name,trank);
				printf("%snumber:%d\n",target_name,sayi);			
				
			}	



		}else if( strcmp(first_flag,"-s")==0 && strcmp(extra_flags,"-r-p-n")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strcmp( (male+i)->name,target_name)==0){

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strcmp( (female + i)->name,target_name)==0){
				
					sayi= (female+i)->numbers;
					trank=(male+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;

					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				printf("%s rank:%d\n",target_name,trank);
				printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				printf("percentage%.10f\n",yuzde);				
				sayi=0;
				trank=0;

			}	



		}else if( strcmp(first_flag,"-s")==0 && strcmp(extra_flags,"-p-n-r")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strcmp( (male+i)->name,target_name)==0){

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strcmp( (female +i)->name,target_name)==0){
				
					sayi= (female+i)->numbers;
					trank=(male+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;

					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				printf("%s rank:%d\n",target_name,trank);
				printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				printf("percentage%.10f\n",yuzde);				
				sayi=0;
				trank=0;

			}	



		}else if( strcmp(first_flag,"-s")==0 && strcmp(extra_flags,"-p-r-n")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strcmp( (male+i)->name,target_name)==0){

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strcmp( (female + i)->name,target_name)==0){
				
					sayi= (female+i)->numbers;
					trank=(male+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;

					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				printf("%s rank:%d\n",target_name,trank);
				printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				printf("percentage%.10f\n",yuzde);				
				sayi=0;
				trank=0;

			}	



		}else if( strcmp(first_flag,"-s")==0 && strcmp(extra_flags,"-n-r-p")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strcmp( (male+i)->name,target_name)==0){

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strcmp( (female + i)->name,target_name)==0){
				
					sayi= (female+i)->numbers;
					trank=(male+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;

					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				printf("%s rank:%d\n",target_name,trank);
				printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				printf("percentage%.10f\n",yuzde);				
				sayi=0;
				trank=0;

			}	



		}else if( strcmp(first_flag,"-s")==0 && strcmp(extra_flags,"-n-p-r")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strcmp( (male+i)->name,target_name)==0){

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strcmp( (female + i)->name,target_name)==0){
				
					sayi= (female+i)->numbers;
					trank=(male+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;

					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				printf("%s rank:%d\n",target_name,trank);
				printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				printf("percentage%.10f\n",yuzde);				
				sayi=0;
				trank=0;

			}	



		
		}else if( strcmp(first_flag,"-s")==0 && strcmp(extra_flags,"-r-n-p")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strcmp( (male+i)->name,target_name)==0){

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strcmp( (female + i)->name,target_name)==0){
				
					sayi= (female+i)->numbers;
					trank=(male+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;


					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				printf("%s rank:%d\n",target_name,trank);
				printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				printf("percentage%.10f\n",yuzde);				

			}	



		

		}else if( strcmp(first_flag,"-v")==0 && strcmp(extra_flags,"-r-n-p")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strstr( (male+i)->name, target_name) != NULL) {//contains

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strstr( (male+i)->name, target_name) != NULL){
				
					sayi= (female+i)->numbers;
					trank=(female+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;

					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				printf("%s rank:%d\n",target_name,trank);
				printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				printf("percentage%.10f\n",yuzde);				

			}	



		

		}else if( strcmp(first_flag,"-v")==0 && strcmp(extra_flags,"-n-p-r")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strstr( (male+i)->name, target_name) != NULL) {//contains

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strstr( (male+i)->name, target_name) != NULL){
				
					sayi= (female+i)->numbers;
					trank=(female+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;

					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				printf("%s rank:%d\n",target_name,trank);
				printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				printf("percentage%.10f\n",yuzde);				

			}	



		

		}else if( strcmp(first_flag,"-v")==0 && strcmp(extra_flags,"-n-r-p")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strstr( (male+i)->name, target_name) != NULL) {//contains

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strstr( (male+i)->name, target_name) != NULL){
				
					sayi= (female+i)->numbers;
					trank=(female+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;

					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				printf("%s rank:%d\n",target_name,trank);
				printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				printf("percentage%.10f\n",yuzde);				

			}	



		

		}else if( strcmp(first_flag,"-v")==0 && strcmp(extra_flags,"-p-r-n")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strstr( (male+i)->name, target_name) != NULL) {//contains

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strstr( (male+i)->name, target_name) != NULL){
				
					sayi= (female+i)->numbers;
					trank=(female+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;

					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				printf("%s rank:%d\n",target_name,trank);
				printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				printf("percentage%.10f\n",yuzde);				

			}	



		

		}else if( strcmp(first_flag,"-v")==0 && strcmp(extra_flags,"-p-n-r")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strstr( (male+i)->name, target_name) != NULL) {//contains

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strstr( (male+i)->name, target_name) != NULL){
				
					sayi= (female+i)->numbers;
					trank=(female+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;

					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				printf("%s rank:%d\n",target_name,trank);
				printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				printf("percentage%.10f\n",yuzde);				

			}	



		

		}else if( strcmp(first_flag,"-v")==0 && strcmp(extra_flags,"-r-p-n")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strstr( (male+i)->name, target_name) != NULL) {//contains

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strstr( (male+i)->name, target_name) != NULL){
				
					sayi= (female+i)->numbers;
					trank=(female+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;

					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				printf("%s rank:%d\n",target_name,trank);
				printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				printf("percentage%.10f\n",yuzde);				

			}	



		

		}else if( strcmp(first_flag,"-v")==0 && strcmp(extra_flags,"-r-n")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strstr( (male+i)->name, target_name) != NULL) {//contains

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strstr( (male+i)->name, target_name) != NULL){
				
					sayi= (female+i)->numbers;
					trank=(female+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;

					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				printf("%s rank:%d\n",target_name,trank);
				printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				//printf("percentage%.10f\n",yuzde);				

			}	



		

		}else if( strcmp(first_flag,"-v")==0 && strcmp(extra_flags,"-n-r")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strstr( (male+i)->name, target_name) != NULL) {//contains

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strstr( (male+i)->name, target_name) != NULL){
				
					sayi= (female+i)->numbers;
					trank=(female+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;

					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				printf("%s rank:%d\n",target_name,trank);
				printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				//printf("percentage%.10f\n",yuzde);				

			}	



		

		}else if( strcmp(first_flag,"-v")==0 && strcmp(extra_flags,"-r-p")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strstr( (male+i)->name, target_name) != NULL) {//contains

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strstr( (male+i)->name, target_name) != NULL){
				
					sayi= (female+i)->numbers;
					trank=(female+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;

					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				printf("%s rank:%d\n",target_name,trank);
				//printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				printf("percentage%.10f\n",yuzde);				

			}	



		

		}else if( strcmp(first_flag,"-v")==0 && strcmp(extra_flags,"-p-r")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strstr( (male+i)->name, target_name) != NULL) {//contains

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strstr( (male+i)->name, target_name) != NULL){
				
					sayi= (female+i)->numbers;
					trank=(female+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;

					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				printf("%s rank:%d\n",target_name,trank);
				//printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				printf("percentage%.10f\n",yuzde);				

			}	



		

		}else if( strcmp(first_flag,"-v")==0 && strcmp(extra_flags,"-p-n")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strstr( (male+i)->name, target_name) != NULL) {//contains

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strstr( (male+i)->name, target_name) != NULL){
				
					sayi= (female+i)->numbers;
					trank=(female+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;

					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				//printf("%s rank:%d\n",target_name,trank);
				printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				printf("percentage%.10f\n",yuzde);				

			}	



		

		}else if( strcmp(first_flag,"-v")==0 && strcmp(extra_flags,"-n-p")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strstr( (male+i)->name, target_name) != NULL) {//contains

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strstr( (male+i)->name, target_name) != NULL){
				
					sayi= (female+i)->numbers;
					trank=(female+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;

					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				//printf("%s rank:%d\n",target_name,trank);
				printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				printf("percentage%.10f\n",yuzde);				

			}	



		

		}else if( strcmp(first_flag,"-v")==0 && strcmp(extra_flags,"-np")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strstr( (male+i)->name , target_name) != NULL) {//contains

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strstr( (male+i)->name , target_name) != NULL){
				
					sayi= (female+i)->numbers;
					trank=(female+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;

					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				//printf("%s rank:%d\n",target_name,trank);
				printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				printf("percentage%.10f\n",yuzde);				

			}	



		

		}else if( strcmp(first_flag,"-v")==0 && strcmp(extra_flags,"-pn")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strstr( (male+i)->name, target_name) != NULL) {//contains

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strstr( (male+i)->name, target_name) != NULL){
				
					sayi= (female+i)->numbers;
					trank=(female+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;

					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				//printf("%s rank:%d\n",target_name,trank);
				printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				printf("percentage%.10f\n",yuzde);				

			}	



		

		}else if( strcmp(first_flag,"-v")==0 && strcmp(extra_flags,"-pr")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strstr( (male+i)->name, target_name) != NULL) {//contains

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strstr( (male+i)->name, target_name) != NULL){
				
					sayi= (female+i)->numbers;
					trank=(female+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;

					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				printf("%s rank:%d\n",target_name,trank);
				//printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				printf("percentage%.10f\n",yuzde);				

			}	



		

		}else if( strcmp(first_flag,"-v")==0 && strcmp(extra_flags,"-rp")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strstr( (male+i)->name, target_name) != NULL) {//contains

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strstr( (male+i)->name, target_name) != NULL){
				
					sayi= (female+i)->numbers;
					trank=(female+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;

					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				printf("%s rank:%d\n",target_name,trank);
				//printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				printf("percentage%.10f\n",yuzde);				

			}	



		

		}else if( strcmp(first_flag,"-v")==0 && strcmp(extra_flags,"-rn")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strstr( (male+i)-> name, target_name) != NULL) {//contains

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strstr( (male+i)->name, target_name) != NULL){
				
					sayi= (female+i)->numbers;
					trank=(female+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;

					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				//printf("%s rank:%d\n",target_name,trank);
				printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				printf("percentage%.10f\n",yuzde);				

			}	



		

		}else if( strcmp(first_flag,"-v")==0 && strcmp(extra_flags,"-rpn")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strstr( (male+i)-> name, target_name) != NULL) {//contains

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strstr( (male+i)->name, target_name) != NULL){
				
					sayi= (female+i)->numbers;
					trank=(female+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;

					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				printf("%s rank:%d\n",target_name,trank);
				printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				printf("percentage%.10f\n",yuzde);				

			}	



		

		}else if( strcmp(first_flag,"-v")==0 && strcmp(extra_flags,"-pnr")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strstr( (male+i)-> name, target_name) != NULL) {//contains

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strstr( (male+i)-> name, target_name) != NULL){
				
					sayi= (female+i)->numbers;
					trank=(female+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;

					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				printf("%s rank:%d\n",target_name,trank);
				printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				printf("percentage%.10f\n",yuzde);				

			}	



		

		}else if( strcmp(first_flag,"-v")==0 && strcmp(extra_flags,"-prn")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strstr( (male+i)->name , target_name) != NULL) {//contains

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strstr( (male+i)->name , target_name) != NULL){
				
					sayi= (female+i)->numbers;
					trank=(female+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;

					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				printf("%s rank:%d\n",target_name,trank);
				printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				printf("percentage%.10f\n",yuzde);				

			}	



		

		}else if( strcmp(first_flag,"-v")==0 && strcmp(extra_flags,"-nrp")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strstr( (male+i)->name, target_name) != NULL) {//contains

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strstr( (male+i)->name , target_name) != NULL){
				
					sayi= (female+i)->numbers;
					trank=(female+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;

					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				printf("%s rank:%d\n",target_name,trank);
				printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				printf("percentage%.10f\n",yuzde);				

			}	



		

		}else if( strcmp(first_flag,"-v")==0 && strcmp(extra_flags,"-npr")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strstr( (male+i)->name , target_name) != NULL) {//contains

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strstr( (male+i)->name , target_name) != NULL){
				
					sayi= (female+i)->numbers;
					trank=(female+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;

					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				printf("%s rank:%d\n",target_name,trank);
				printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				printf("percentage%.10f\n",yuzde);				

			}	



		

		}else if( strcmp(first_flag,"-v")==0 && strcmp(extra_flags,"-rnp")==0){
				
			int toplam_sayi=0;
			int sayi=0;
			int trank=0;
			for(int i=0;i<1000;i++){

				if(strstr( (male+i)->name , target_name) != NULL) {//contains

					sayi= (male+i)->numbers;	
					trank=(male+i)->rank;					

				}else if(strstr( (male+i)->name, target_name) != NULL){
				
					sayi= (female+i)->numbers;
					trank=(female+i)->rank;
				}

				
				toplam_sayi+=(male+i)->numbers;
				toplam_sayi+=(female+i)->numbers;

					

			}
			if(sayi==0){
				printf("There is not a target_name\n");			
			}else{
				printf("%s rank:%d\n",target_name,trank);
				printf("%snumber:%d\n",target_name,sayi);			
				double yuzde= (sayi/toplam_sayi)*100;
				printf("percentage%.10f\n",yuzde);				

			}	



		

		}



		for(int i=0;i<5;i++){
			free((male+i)->name);

		}
		for(int i=0;i<5;i++){
			free((female+i)->name);

		}
		free(male);
		free(female);
	
		
	

	 }	

}

int flag_mi(char *c){

	if(c[0]=='-')
		return 0;
	else

		return 1;


}

