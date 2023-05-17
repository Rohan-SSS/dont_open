import math

def minimax(curDepth, nodeIndex, maxTurn, scores, targetDepth):
    if curDepth == targetDepth:
        return scores[nodeIndex]
    
    if maxTurn:
        return max(
            minimax(curDepth+1, nodeIndex*2, False, scores, targetDepth),
            minimax(curDepth+1, nodeIndex*2+1, False, scores, targetDepth)
        )
    else:
        return min(
            minimax(curDepth+1, nodeIndex*2, True, scores, targetDepth),
            minimax(curDepth+1, nodeIndex*2+1, True, scores, targetDepth)
        )

scores = [-21,31,15,-23,-18,12,-29,26]
treeDepth = int(math.log2(len(scores)))

print(scores)
print(treeDepth)
print("Optimal value is:", minimax(0, 0, True, scores, treeDepth))
