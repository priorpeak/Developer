from requests import get
from requests.exceptions import RequestException
from contextlib import closing
from bs4 import BeautifulSoup
import csv

if __name__ == "__main__":
    raw_html = open('electronics-html.txt')
    html = BeautifulSoup(raw_html,'html.parser')
    for product in html.select('div'):
        if product['class'][0] == '_1g9xn5a':
            try:
                #print(product)
                print(product.find('h4').text + ',' + product.find('h3').text[1:-1]+','+product.find('div',{'class':"_nfsbxmj"}).text)
            except UnicodeEncodeError:
                print(product.text.encode('ascii','ignore'))
            
