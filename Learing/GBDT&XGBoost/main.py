import numpy as np
from pandas import Series,DataFrame
from sklearn.preprocessing import LabelEncoder,OneHotEncoder
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
from sklearn.metrics import roc_auc_score
import pandas as pd
from sklearn import ensemble
import xgboost as xgb
import matplotlib.pyplot as plt
import random

OneHot_GBDT_score=[]
Label_GBDT_score=[]
OneHot_XGB_score=[]
Label_XGB_score=[]
seed=[]
for i in range(0,10):
    seed.append(random.randint(0,123456))

pd.set_option('display.max_columns', None)
pd.set_option('display.width', 1000)
data1=pd.read_csv('train.csv',header=None)
data2=pd.read_csv('train.csv',header=None)
data1.columns=['age','workclass','fnlwgt','education','education-num','marital_Status','occupation','relationship','race','sex','capital_gain','capital_loss','hours_per_week','native_country','Income']
data2.columns=['age','workclass','fnlwgt','education','education-num','marital_Status','occupation','relationship','race','sex','capital_gain','capital_loss','hours_per_week','native_country','Income']

l=LabelEncoder()
l.fit(data1.Income)
data1.Income=Series(l.transform(data1.Income))  # 将收入是否大于50k用0和1表示
X1=data1.drop('Income',axis=1)
y1=data1.Income
y1.fillna(y1.mode()[0],inplace=True)
trans = {'workclass' : X1['workclass'].mode()[0], 'occupation' : X1['occupation'].mode()[0], 'native_country' : X1['native_country'].mode()[0]}
X1.fillna(trans, inplace = True)
l.fit(data2.Income)
data2.Income=Series(l.transform(data2.Income))
X2=data2.drop('Income',axis=1)
y2=data2.Income
y2.fillna(y2.mode()[0],inplace=True)
trans = {'workclass' : X2['workclass'].mode()[0], 'occupation' : X2['occupation'].mode()[0], 'native_country' : X2['native_country'].mode()[0]}
X2.fillna(trans, inplace = True)

def OneHot(data):
    one_hot_workclass = pd.get_dummies(data.workclass)
    one_hot_education = pd.get_dummies(data.education)
    one_hot_marital_Status = pd.get_dummies(data.marital_Status)
    one_hot_occupation = pd.get_dummies(data.occupation)
    one_hot_relationship = pd.get_dummies(data.relationship)
    one_hot_race = pd.get_dummies(data.race)
    one_hot_sex = pd.get_dummies(data.sex)
    one_hot_native_country = pd.get_dummies(data.native_country)
    data.drop(['workclass', 'education', 'marital_Status', 'occupation', 'relationship','race', 'sex', 'native_country', 'capital_gain', 'capital_loss', 'fnlwgt'], axis=1, inplace=True)
    data = pd.concat([data, one_hot_workclass, one_hot_education, one_hot_marital_Status,
                      one_hot_occupation, one_hot_relationship, one_hot_race, one_hot_sex,
                      one_hot_native_country], axis=1)
    _, i = np.unique(data.columns, return_index=True)
    data = data.iloc[:, i]
    return data
def LabelEncode(data):
    encoder = LabelEncoder()
    cols_to_encode = ['workclass', 'education', 'marital_Status', 'occupation', 'relationship', 'race', 'sex','native_country']
    for col in cols_to_encode:
        data[col] = encoder.fit_transform(data[col])
    return data
def GBDT(trainx,testx,trainy,testy):
    clf1 = ensemble.GradientBoostingClassifier()
    clf1.fit(trainx, trainy)
    Test_score = clf1.score(testx, testy)
    return Test_score
def XGBoost(trainx,testx,trainy,testy):
    dtrain = xgb.DMatrix(trainx, label=trainy)
    dtest = xgb.DMatrix(testx)
    parameters = {'max_depth': 7, 'eta': 1, 'silent': 1, 'objective': 'binary:logistic', 'eval_metric': 'auc',
                  'learning_rate': .05}
    num_round = 50  # 模型迭代次数
    xg = xgb.train(parameters, dtrain, num_round)
    ypred = xg.predict(dtest)
    for i in range(len(ypred)):
        ypred[i] = 1 if ypred[i] > 0.5 else 0
    auc_xgb = roc_auc_score(testy, ypred)
    return auc_xgb
X1=OneHot(X1)
X2=LabelEncode(X2)
for i in range(0,10):
    OneHot_trainx, OneHot_testx, OneHot_trainy, OneHot_testy = train_test_split(X1, y1, test_size=.3,random_state=seed[i])
    Label_trainx,Label_testx,Label_trainy,Label_testy=train_test_split(X2,y2,test_size=.3,random_state=seed[i])
    Label_GBDT_score.append(GBDT(Label_trainx,Label_testx,Label_trainy,Label_testy))
    OneHot_GBDT_score.append(GBDT(OneHot_trainx,OneHot_testx,OneHot_trainy,OneHot_testy))
    Label_XGB_score.append(XGBoost(Label_trainx,Label_testx,Label_trainy,Label_testy))
    OneHot_XGB_score.append(XGBoost(OneHot_trainx,OneHot_testx,OneHot_trainy,OneHot_testy))

x=[1,2,3,4,5,6,7,8,9,10]
plt.plot(x,OneHot_GBDT_score,label="OneHot(GBDT)")
plt.plot(x,Label_GBDT_score,label="Label(GBDT)")
plt.plot(x,Label_XGB_score,label="Label(XGB)")
plt.plot(x,OneHot_XGB_score,label="OneHot(XGB)")
plt.ylabel('score')
plt.legend(loc='best')
plt.show()