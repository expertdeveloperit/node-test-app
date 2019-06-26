import { fact } from '../../../build/Release/addon'
import { success } from '../../services/response/'

// calculating the factorial of number passed in request body using c++ addon {fact}
export const factorial = (req, res, next) => {
  const { number } = req.body
  try {
    let result = fact(Number(number))
    success(res, 201)({ result: `Factorial of number ${number} is = ${result}.` })
  } catch (e) {
    next(e.message)
  }
}
