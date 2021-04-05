#!/usr/bin/env python
# coding: utf-8

# In[52]:


import matplotlib.pyplot as plt
import math


# In[53]:


x=[12.3,14.3,14.5,14.8,16.1,16.5,15.3,17.0,17.8,20.2,20.2,22.3,19.3]
y=[11.8,12.7,13.0,11.8,14.3,13.5,13.8,14.9,15.7,18.6,18.8,20.1,15.0]


# In[54]:


print(len(x))


# In[55]:


x_train = x[0:8]
y_train = y[0:8]
n_train = len(x_train)

x_test = x[8:]
y_test = y[8:]
n_test = len(x_test)


# In[56]:


w = -0.1
b = 3

lr =0.00001


# In[57]:


epoches =100
for i in range(epoches):
    sum_w = 0.0
    sum_b = 0.0
    for i in range(n_train):
        y_hat = w * x_train[i] +b
        sum_w +=(y_train[i]-y_hat) * (-x_train[i])
        sum_b +=(y_train[i]-y_hat) * (-1)
    det_w = 2 * sum_w
    det_b = 2 * sum_b
    
    w = w - lr * det_w
    b = b - lr * det_b


# In[58]:


fig,ax=plt.subplots()
ax.scatter(x_train,y_train)
ax.plot([i for i in range(10,27)],[w * i + b for i in range(10,27)])
plt.title('y = w * x + b')
plt.legend(('Mobel','Data Points'),loc='upper left')
plt.show()


# In[59]:


total_train_loss = 0
for i in range(n_train):
    y_hat = w * x_train[i] + b
    total_train_loss += (y_train[i] - y_hat) ** 2


# In[60]:


total_test_loss = 0
for i in range(n_test):
    y_hat = w * x_test[i] + b
    total_test_loss += (y_test[i] - y_hat) ** 2


# In[61]:


print(total_train_loss)


# In[62]:


print(total_test_loss)


# In[ ]:





# In[ ]:





# In[ ]:




