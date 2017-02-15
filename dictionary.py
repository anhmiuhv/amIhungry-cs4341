#characters
dictHumidity= {'low':0.2, 'medium':0.5, 'high' : 0.3}
dictTemp = {'warm':0.1 ,'mild':0.4 ,'cold':0.5}
dictDay = {'weekend':0.2,'weekday':0.8}

#cpt of two things
#dict of Icy inputs are humid first, temp second
dictIcyTrue = {'lowwarm':0.001, 'lowmild':0.01,'lowcold':0.05}
dictIcyTrue.update({'mediumwarm':0.001,'mediummild':0.03,'mediumcold':0.2})
dictIcyTrue.update({'highwarm':0.005,'highmild':0.01,'highcold':0.35})

#dict of snow inputs are humid first, temp second
dictSnowTrue = {'lowwarm':0.0001, 'lowmild':0.001,'lowcold':0.1}
dictSnowTrue.update({'mediumwarm':0.0001,'mediummild':0.0001,'mediumcold':0.25})
dictSnowTrue.update({'highwarm':0.0001,'highmild':0.001,'highcold':0.4})

#dict of cloud input is cloud
dictCloudTrue = {'false': 0.3, 'true': 0.9}

#dict of exam inputs are snow first, day second
dictExamTrue = {'falseweekend':0.001,'falseweekday':0.1}
dictExamTrue.update({'trueweekend':0.0001,'trueweekday':0.3})

#dict of stress inputs are snow first, exam second
dictStressTrue = {'falsefalse':0.001,'falsetrue':0.1}
dictStressTrue.update({'truefalse':0.0001,'truetrue':0.3})
