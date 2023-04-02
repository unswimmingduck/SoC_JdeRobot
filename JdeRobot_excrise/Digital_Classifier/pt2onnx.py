import torch
import torch.nn
import onnx
from mnist_train import Net


model = torch.load('mnist_cnn.pt')

model.eval()
 
input_names = ['input']
output_names = ['output']
 
x = torch.randn(1,1,28,28,requires_grad=True, device='cuda')
 
torch.onnx.export(model, x, 'best.onnx', input_names=input_names, output_names=output_names, verbose='True')