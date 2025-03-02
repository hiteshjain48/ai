from keras.datasets import fashion_mnist
(train_X, train_Y), (test_X,test_Y) = fashion_mnist.load_data()

import numpy as np
from keras.utils import to_categorical

train_X = train_X.reshape(-1, 28,28,1).astype("float32") / 255.
test_X = test_X.reshape(-1, 28,28,1).astype("float32") / 255.

train_Y_one_hot = to_categorical(train_Y)
test_Y_one_hot = to_categorical(test_Y)

from sklearn.model_selection import train_test_split

train_X, valid_X, train_label, valid_label = train_test_split(train_X, train_Y_one_hot, test_size= 0.2, random_state=42)

from tensorflow import keras

model = keras.Sequential([
    keras.layers.Conv2D(64, (3,3), input_shape = (28,28,1), activation='relu'),
    keras.layers.MaxPooling2D(pool_size=(2,2)),

    keras.layers.Conv2D(64, (3,3), activation='relu'),
    keras.layers.MaxPooling2D(pool_size=(2,2)),
    
    keras.layers.Flatten(),
    keras.layers.Dense(64),
    keras.layers.Dense(10, activation='softmax')
])



model.compile(loss = keras.losses.categorical_crossentropy, optimizer='adam', metrics=['accuracy'])

model.fit(train_X, train_label, batch_size=64, epochs=5)

predicted_values = model.predict(test_X)

predicted_values = np.argmax(np.round(predicted_values), axis=1)

from sklearn.metrics import classification_report
target_names=["Class {}".format(i) for i in range(10)]
print(classification_report(test_Y, predicted_values, target_names=target_names))
