agree = {
		'q1':{'0':['0',1,'q1'],  '1':['1',1,'q1'],  '2':['2',1,'q1'],  '+':['+',1,'q2'],  '-':['-',1,'q5'],  ' ':[' ',1,'q1'] },
		'q2':{'0':['0',0,'q10'], '1':['1',-1,'q3'], '2':['2',-1,'q4']													 	  },
		'q3':{'0':['1',0,'q10'], '1':['2',0,'q10'], '2':['0',-1,'q3'], '+':['+',-1,'q3'], 					 ' ':['1',0,'q10']},
		'q4':{'0':['2',0,'q10'], '1':['0',-1,'q3'], '2':['1',-1,'q3'], '+':['+',-1,'q4'], 					 ' ':['2',0,'q10']},
		'q5':{'0':['0',0,'q10'], '1':['1',-1,'q6'], '2':['2',-1,'q7']						 								  },
		'q6':{'0':['2',-1,'q6'], '1':['0',0,'q8'],  '2':['1',0,'q10'], 					  '-':['-',-1,'q6']					  },
		'q7':{'0':['1',-1,'q6'], '1':['2',-1,'q6'], '2':['0',0,'q9'], 					  '-':['-',-1,'q7']					  },
		'q8':{'0':['0',-1,'q8'], '1':['1',-1,'q8'], '2':['2',-1,'q8'], '+':['+',1,'q8'],  '-':['-',-1,'q8'], ' ':[' ',1,'q9'] },
		'q9':{'0':[' ',1,'q9'],  '1':['1',0,'q10'], '2':['2',0,'q10'], 				      '-':['-',-1,'q9'], ' ':['0',0,'q10']}
		}

mtape = list(input())
q = 'q1'
i = 0
while q!='q10':
    cell = mtape[i]
    mtape[i] = agree[q][cell][0]
    i += agree[q][cell][1]
    q = agree[q][cell][2]
mtape = ''.join(mtape)
print(mtape)