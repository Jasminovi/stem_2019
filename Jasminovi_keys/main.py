from difflib import SequenceMatcher
import jellyfish
for i in range(0,10):
    dat = open("C:\\Users\\Makky\\Desktop\\keys\\test_cases\\keys_"+str(i)+".in")
    sadrzaj = dat.read()
    polje = sadrzaj.split("\n")
    maks = 10000000000
    najbolji = 0
    broj = polje[0].split(" ")[0]
    unos = polje[0].split(" ")[1]
    print(i)
    print("\nBroj: ",broj)


    for i in range(1,int(broj)+1):
        temp = jellyfish.levenshtein_distance(unos, polje[i])
        #temp = similar(unos, polje[i])
        
        if temp < maks :
            maks = temp
            najbolji = i-1

    print("\nPozicija: ",najbolji)
    #print("\nNajbolji: ",maks)
