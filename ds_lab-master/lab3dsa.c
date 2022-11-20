    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    struct employee{
            int id;
            char name[20];
            float salary;
    }emp[10];
    int main()
    {       
            int n,opt,count=0,ids,foundid=-1,foundname=-1,hpayid,startid;
            char idn[20];
            float hpay;
            do{
        
        idchecker: 
            printf("\n-----------------------------------");    
            printf("\n1-add employe.\n2-display all employee.\n3-search employee using empid.\n-4-search using name.\n-5-employee with the highest salary.\n-6-exit:");
            scanf("%d",&opt);
        switch (opt){
                case 1:printf("\n-----------------------------------");
                            printf("\nenter the employee id,name and salary:");
                            scanf("%d%s%f",&emp[count].id,emp[count].name,&emp[count].salary);                
                            if(count!=0)
                                {startid=emp[count].id;
                                for(int i=0;i<count;i++)
                                    {if(startid==emp[i].id)
                                        {
                                        printf("\nthis id already exists,please enter a new id...");
                                        goto idchecker;
                                        }        
                                    }        
                                }
                            printf("\nemployee info entered");    
                            count++;
                            break;
            case 2:if(count==0)
                            {
                            printf("\n-----------------------------------");    
                            printf("\nno employees in the database");        
                            }
                            else
                            {       printf("\n-----------------------------------");
                                    printf("\nid\tname\tpay");
                            for(int i=0;i<count;i++)        
                                    {
                                printf("\n%d\t%s\t%f",emp[i].id,emp[i].name,emp[i].salary);       
                                    }
                            }
                            break;
            case 3:if(count==0)
                            {
                            printf("\n-----------------------------------");    
                            printf("\nno employees in the database");        
                            }
                            else
                            {   printf("\n-----------------------------------");
                            printf("\nenter the id to be searched");        
                            scanf("%d",&ids);
                            for(int i=0;i<count;i++)
                                    {
                                    if(ids==emp[i].id)
                                            {
                                            foundid=i;
                                            break;
                                            }
                                    }
                                    if(foundid==-1)
                                            {
                                            printf("\n-----------------------------------");   
                                            printf("\nemployee not found");        
                                            }
                                    else
                                            {
                                            printf("\nemployee found");
                                            printf("\n-----------------------------------");
                                            printf("\nid\tname\tpay");
                                            printf("\n%d\t%s\t%f",emp[foundid].id,emp[foundid].name,emp[foundid].salary);
                                            }
                                    foundid=-1;
                            }
                            break;
            case 4:if(count==0)
                            {
                            printf("\n-----------------------------------");    
                            printf("\nno employees in the database");        
                            }
                            else
                            {printf("\n-----------------------------------");
                            printf("\nenter name to be searched");
                            scanf("%s",idn);
                            for(int i=0;i<count;i++)
                                    {
                                    if((strcmp(idn,emp[i].name))==0)
                                            {
                                            foundname=i;
                                            break;
                                            }
                                    }
                            if(foundname==-1)        
                            {
                            printf("\n-----------------------------------");    
                            printf("\nemployee not found");        
                            }
                            else
                            {
                            printf("\nemployee found");
                            printf("\n-----------------------------------");
                            printf("\nid\tname\tpay");
                            printf("\n%d\t%s\t%f",emp[foundname].id,emp[foundname].name,emp[foundname].salary);
                            }
                            foundname=-1;
                            }
                            break;
            case 5:if(count==0)
                            {
                            printf("\nno employees in the database");        
                            }
                            else
                            {
                            hpay=0;
                            hpayid=0;
                            for(int i=0;i<count;i++)
                                    {
                                    if(hpay<emp[i].salary)
                                            {
                                            hpay=emp[i].salary;        
                                            hpayid=i;        
                                            }
                                    }
                            printf("\n-----------------------------------");        
                            printf("\nthe highest pay is of employee with id %d,name %s and is equal to %f",emp[hpayid].id,emp[hpayid].name,hpay);        
                            hpay=0;
                            hpayid=0;
                            }
                            break;
            case 6:printf("\nprogram exited");
                            exit(0);
                            break;
            default:printf("\nplease enter a valid choice");
                            break;
        }
        }while(1);
    }