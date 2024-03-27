import requests
from bs4 import BeautifulSoup
import re

def fetch_main_content(url):
    try:
        response = requests.get(url)
        if response.status_code == 200:
            soup = BeautifulSoup(response.text, 'html.parser')
            main_content_tag = soup.find('main')
            if main_content_tag:
                text_content = main_content_tag.get_text()
                print(text_content)
                url_count = count_urls(text_content)
                print(f"Number of URLs in the webpage: {url_count}")
                save_to_file(text_content, 'text.txt')
            else:
                print("Main content not found on the webpage.")
        else:
            print(f"Failed to fetch URL. Status code: {response.status_code}")

    except Exception as e:
        print(f"An error occurred: {str(e)}")

def count_urls(text):
    url_pattern = re.compile(r'http[s]?://(?:[a-zA-Z]|[0-9]|[$-_@.&+]|[!*\\(\\),]|(?:%[0-9a-fA-F][0-9a-fA-F]))+')
    urls = re.findall(url_pattern, text)
    return len(urls)

def save_to_file(content, file_path):
    with open(file_path, 'w',encoding="utf-8") as file:
        file.write(content)

url_to_fetch = "https://en.wikipedia.org/wiki/Jamia_Millia_Islamia"
print("\n")
print("\n")

fetch_main_content(url_to_fetch)

number_of_words = 1

with open(r'text.txt','r',encoding="utf-8") as file:
 
    data = file.read()
    lines = data.split()
    number_of_words += len(lines)
 
number_of_words=str(number_of_words)

print("Number of words in text file: " + number_of_words)


def count_non_empty_lines(file_path):
    try:
        # Open the file in read mode
        with open(file_path, 'r', encoding='utf-8') as file:
            # Read all lines from the file
            lines = file.readlines()

            # Count non-empty lines
            non_empty_lines = sum(1 for line in lines if line.strip())

            return non_empty_lines

    except FileNotFoundError:
        print(f"File not found: {file_path}")
        return 0
    except Exception as e:
        print(f"An error occurred: {str(e)}")
        return 0

file_path = 'text.txt'
lines_count = count_non_empty_lines(file_path)
print(f"Number of non-empty lines in '{file_path}': {lines_count}")
print("\n")




'''
import requests
from bs4 import BeautifulSoup

def fetch_main_content(url):
    try:
        # Send a GET request to the URL
        response = requests.get(url)

        # Check if the request was successful (status code 200)
        if response.status_code == 200:
            # Parse the HTML content with BeautifulSoup
            soup = BeautifulSoup(response.text, 'html.parser')

            # Find the main content element (modify this based on the structure of the webpage)
            main_content_tag = soup.find('main')

            # Check if the main content element exists
            if main_content_tag:
                # Extract text content without HTML tags from the main content
                text_content = main_content_tag.get_text()

                # Print the text content
                print(text_content)
                
                lines_1 = [text_content]  
                with open('text.txt', 'w') as file:  
                    # Iterating over each element of the list  
                    for line_1 in lines_1:  
                        file.write(line_1)  # Adding the line to the text.txt  
                        # file.write('\n')  # Adding a new line character  
            else:
                print("Main content not found on the webpage.")

        else:
            print(f"Failed to fetch URL. Status code: {response.status_code}")

    except Exception as e:
        print(f"An error occurred: {str(e)}")

# Example usage:
url_to_fetch = "https://aws.amazon.com/what-is/java/#:~:text=Java%20is%20a%20widely%2Dused,as%20a%20platform%20in%20itself."
fetch_main_content(url_to_fetch)


number_of_words = 1

with open(r'text.txt','r') as file:
 
    data = file.read()
    lines = data.split()
    number_of_words += len(lines)
 
 
# Printing total number of words
print("\n")
print("\n")

number_of_words=str(number_of_words)

print("Number of words in text file - " + number_of_words)


def count_non_empty_lines(file_path):
    try:
        # Open the file in read mode
        with open(file_path, 'r', encoding='utf-8') as file:
            # Read all lines from the file
            lines = file.readlines()

            # Count non-empty lines
            non_empty_lines = sum(1 for line in lines if line.strip())

            return non_empty_lines

    except FileNotFoundError:
        print(f"File not found: {file_path}")
        return 0
    except Exception as e:
        print(f"An error occurred: {str(e)}")
        return 0

file_path = 'text.txt'
lines_count = count_non_empty_lines(file_path)
print(f"Number of non-empty lines in '{file_path}': {lines_count}")
'''
