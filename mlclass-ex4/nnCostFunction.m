function [J grad] = nnCostFunction(nn_params, ...
                                   input_layer_size, ...
                                   hidden_layer_size, ...
                                   num_labels, ...
                                   X, y, lambda)
%NNCOSTFUNCTION Implements the neural network cost function for a two layer
%neural network which performs classification
%   [J grad] = NNCOSTFUNCTON(nn_params, hidden_layer_size, num_labels, ...
%   X, y, lambda) computes the cost and gradient of the neural network. The
%   parameters for the neural network are "unrolled" into the vector
%   nn_params and need to be converted back into the weight matrices. 
% 
%   The returned parameter grad should be a "unrolled" vector of the
%   partial derivatives of the neural network.
%

% Reshape nn_params back into the parameters Theta1 and Theta2, the weight matrices
% for our 2 layer neural network
Theta1 = reshape(nn_params(1:hidden_layer_size * (input_layer_size + 1)), ...
                 hidden_layer_size, (input_layer_size + 1));

Theta2 = reshape(nn_params((1 + (hidden_layer_size * (input_layer_size + 1))):end), ...
                 num_labels, (hidden_layer_size + 1));

% Setup some useful variables
m = size(X, 1);
         
% You need to return the following variables correctly 
J = 0;
Theta1_grad = zeros(size(Theta1));
Theta2_grad = zeros(size(Theta2));

% ====================== YOUR CODE HERE ======================
% Instructions: You should complete the code by working through the
%               following parts.
%
% Part 1: Feedforward the neural network and return the cost in the
%         variable J. After implementing Part 1, you can verify that your
%         cost function computation is correct by verifying the cost
%         computed in ex4.m
%
% Part 2: Implement the backpropagation algorithm to compute the gradients
%         Theta1_grad and Theta2_grad. You should return the partial derivatives of
%         the cost function with respect to Theta1 and Theta2 in Theta1_grad and
%         Theta2_grad, respectively. After implementing Part 2, you can check
%         that your implementation is correct by running checkNNGradients
%
%         Note: The vector y passed into the function is a vector of labels
%               containing values from 1..K. You need to map this vector into a 
%               binary vector of 1's and 0's to be used with the neural network
%               cost function.
%
%         Hint: We recommend implementing backpropagation using a for-loop
%               over the training examples if you are implementing it for the 
%               first time.
%
% Part 3: Implement regularization with the cost function and gradients.
%
%         Hint: You can implement this around the code for
%               backpropagation. That is, you can compute the gradients for
%               the regularization separately and then add them to Theta1_grad
%               and Theta2_grad from Part 2.
%

% Theta1 is 25*401
% Theta2 is 10*26

%% implement the feedprogation in matrix style
% a1 is 5000*401
a1 = [ones(m,1) X];
% z2 is 5000*25
z2 = a1 * Theta1'; 
% a2 is 5000*26
a2 = [ones(m,1) sigmoid(z2)];
% hypo is 5000 * 10
z3 = a2 * Theta2';
hypo = sigmoid(z3);


%y is 5000 * 10 change y to a 5000*10 matrix
% with the index =1 if y is the lable
% Notice HERE!!
y = eye(num_labels)(y,:);
% cost function
for i = 1: m
	J = sum(-y(i,:) * log(hypo(i,:))' - (1-y(i,:)) * log(1- hypo(i,:))' ) + J;
end
% ignore the column zero so,
% theta1 is 25*400
% theta2 is 10*25
theta1 = Theta1(:,2:end);
theta2 = Theta2(:,2:end);
reg_terms = lambda/(2*m) * (sum(sum(theta1.^2)) + sum(sum(theta2.^2)))
J = J / m + reg_terms;


% Bp implement in matrix
% delta3 is m*s3
delta3 = hypo - y;
% delta2 is m*s2
delta2 = delta3 * theta2 .* sigmoidGradient(z2);
reg1 = lambda * Theta1;
reg1(:,1) = 0;
reg2 = lambda * Theta2;
reg2(:,1) = 0;
Theta1_grad = (delta2' * a1 + reg1)/m;
Theta2_grad = (delta3' * a2 + reg2)/m;

% for t = i : m
% 	x = X(t,:);
% 	% a1 is a column vector 401*1
% 	a1 = [1 x]';
% 	z2 = Theta1 * a1;
% 	% a2 is column vector 26*1
% 	a2 = [1 sigmoid(z2)]';
% 	z3 = Theta2 * a2;
% 	% a3 is column vector 10*1
% 	a3 = sigmoid(z3);

% 	delta3 = a3 - y(t)';
% 	delta2 = theta2'*delta3 .* sigmoidGradient(z2);







% -------------------------------------------------------------

% =========================================================================

% Unroll gradients
grad = [Theta1_grad(:) ; Theta2_grad(:)];


end
