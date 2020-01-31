import Pandas as pd
from sklearn.feature_extraction.text import CountVectorizer
import csv

if __name__ == __main__:
    vectorizer = CountVectorizer();
    
    with open('offerupdata-2.csv','rb') as csvfile:
        reader = csv.reader(csvfile)
        for row in reader:
            
