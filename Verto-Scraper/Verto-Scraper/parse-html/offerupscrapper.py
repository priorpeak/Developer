from requests import get
from requests.exceptions import RequestException
from contextlib import closing
from bs4 import BeautifulSoup
import csv
if __name__ == "__main__":
    raw_html = open('electronics-html.txt')
    html = BeautifulSoup(raw_html,'html.parser')
    csv = open('electronics.csv','w')
    column = 'title,price,img,href,city,state\n'
    csv.write(column)
    for product in html.select('a'):
        if product['class'][1] == 'db-item-tile':
            try:
                item = product.find('span', {'class', '_nn5xny4'}).text.replace(',',' ') + ',' + product.find('span', {'class', '_s3g03e4'}).text.replace(',','') + ',' + product.find('img')['src'] + ',' + product['href'] + '\n'
                csv.write(item)
            except UnicodeEncodeError:
                print('UnicodeEncodeError')
                print(product)
                product = product.encode('ascii','ignore')
                item = product.find('h4').text + ',' + product.find('h3').text[1:-1]+','+product.find('div',{'class':"_17p3u5e"}).text + '\n'
                csv.write(item)
            except AttributeError:
                item = product.find('h4').text.replace(","," ") + ',' + product.find('h3').text[1:-1]+','+product.find('div',{'class':"_17p3u5e"}).text + '\n'
                csv.write(item)
                
                
            
