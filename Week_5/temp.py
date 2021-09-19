maxi=None
mini=None


while True:
	num=input("Enter num:")
	if(num=="done"):
		break
	try:
		fnum=int(num)
	except:
		print("Invalid Input")
		continue

	if(maxi==None):
		maxi=fnum
	elif(maxi<fnum):
		maxi=fnum
	if(mini==None):
		mini=fnum
	elif(mini>fnum):
		mini=fnum

print("Maximum is ",maxi)
print("Minimum is ",mini)