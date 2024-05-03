import nltk
import re
from nltk.tokenize import word_tokenize
from nltk.stem import WordNetLemmatizer

# download necessary NLTK data
# nltk.download('punkt')
# nltk.download('wordnet')

# Define patterns and responses
patterns_responses = [
    (r"hi|hello|hey", ["Hello!", "Hey there!", "Hi!"]),
    (r"how are you ?", ["I'm doing well, thank you!", "I'm fine, thanks! How about you?"]),
    (r"(.*) your name ?", ["I'm a chatbot. You can call me ChatBot.", "You can call me ChatBot."]),
    (r"(.*) (age|old) ?", ["I don't have an age. I'm just a computer program.", "I'm ageless!"]),
    (r"what (.*) want ?", ["I'm here to help and chat with you.", "I'm here to assist you."]),
    (r"(.*) created ?", ["I was created by .", "I'm a product of OpenAI."]),
    (r"(.*) (location|city) ?", ["I exist in the digital world. You can find me wherever you are connected to the internet."]),
    (r"(.*) (thank you|thanks) ?", ["You're welcome!", "No problem!"]),
    (r"bye|goodbye", ["Goodbye!", "Bye! Take care!"]),
]

# Initialize lemmatizer
lemmatizer = WordNetLemmatizer()

def preprocess(sentence):
    tokens = word_tokenize(sentence)
    lemmatized_tokens = [lemmatizer.lemmatize(token.lower()) for token in tokens]
    return lemmatized_tokens

def respond(user_input):
    for pattern, responses in patterns_responses:
        if re.match(pattern, user_input):
            response = responses[0]  # Choose the first response in the list
            return response
    return "I'm sorry, I don't understand that query."

def add_query(user_input):
    response = input("I'm sorry, I don't understand that query. Please provide a response for it: ")
    patterns_responses.append((user_input, [response]))

# Example usage
print("Welcome! How can I help you today?")
while True:
    user_input = input("> ")
    if user_input.lower() == "bye":
        print("Goodbye! Take care!")
        break
    else:
        processed_input = preprocess(user_input)
        response = respond(' '.join(processed_input))
        if response.startswith("I'm sorry"):
            add_query(' '.join(processed_input))
            print("Thank you for providing the response! I'll remember it for next time.")
        else:
            print(response)