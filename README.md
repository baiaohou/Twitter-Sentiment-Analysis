# Twitter-Sentiment-Analysis

## Author: Leo Baiao Hou ***(Inplemented in C++)***

In this program, we are implementing a a program that will analyze the sentiment (positive or negative) of a sentence based on the words it contains. Evaluated ~300,000 pcs of Twitter data and generate a dictionary of words with sentiment. Classified user attributes using their Tweets, and analyzed lexical markers for age / gender / political preferences.

### Overview

Sentiment analysis is a task from the field of computational linguistics that seeks to determine the general attitude of a given piece of text. For instance, we would like to have a program that could look at the text ```This experience was joyful and a pleasure``` and realize that it was a positive statement while ```It made me want to pull out my hair``` is negative. 

One algorithm that we can use for this is to assign a numeric value to any given word based on how positive or negative that word is and then determine the overall sentiment of the statement based on the average values of the words. 

To determine the sentiment of an individual word, we can use a corpus of statements, each of which has an overall score already assigned to it. The sentiment of an individual word equals the average of the statements in which that word appears.

For instance, our corpus may look like this:

```
0 This was not as much fun as I thought it would be .
1 I had a lot of fun on this and learned a lot .
-1 It would be more fun if we had more time to work on it .
2 I didn’t think programming in C++ could be so much fun !
-2 I would have preferred an easier assignment .
2 I can’t think of anything more fun than learning C++ !
```

Each statement is labeled with a score from -2 to 2 as follows:
```
-2: very negative
-1: somewhat negative
0: neutral
1: somewhat positive
2: very positive
```

To determine the overall sentiment of the word “fun,” we take the average of the sentences in which it appears. In this case, it would be ```(0 + 1 + -1 + 2 + 2) / 5 = 0.8.```

Then, given a new sentence, we can determine its sentiment by computing the average of the sentiments of the individual words it contains. The sentiment of any previously unseen word would be 0. This program will evaluate ~300,000 pcs of Twitter data (from ```reviews.txt```) and generate a dictionary of words with sentiment.
